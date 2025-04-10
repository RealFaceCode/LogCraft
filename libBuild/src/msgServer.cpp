#include "msgServer.hpp"

#include <memory>

#include "write.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"

namespace lc
{
    namespace internal
    {
        MsgServerConfig g_msgServerConfig;
        util::ThreadPool<LogMsg> g_threadPoolConsole;
        util::ThreadPool<LogMsg> g_threadPoolFile;
        FileObserver g_fileObserver;

        LC_API void StartMsgServer()
        {
            g_threadPoolConsole.setTaskFunc([](const LogMsg& msg) -> std::optional<int>
            {
                const auto& lConfig = GetLogConfig(msg.m_sLevel);
                if(!lConfig.has_value() || !lConfig.value().get().m_bLogToConsole)
                    return std::nullopt;

                auto LogMsg = BuildMessage(msg.m_sLevel, msg.m_sLabel, msg.m_strMsg, msg.m_sourceLocation.function_name(), msg.m_sourceLocation.file_name(), msg.m_sourceLocation.line(), msg.m_backtrace);
                WriteToConsole(LogMsg);

                return std::nullopt;
            });

            g_threadPoolConsole.setThreadCount(g_msgServerConfig.m_nMaxThreadsTerminal);
            g_threadPoolConsole.start();

            g_threadPoolFile.setTaskFunc([](const LogMsg& msg) -> std::optional<int>
            {
                const auto& lConfig = GetLogConfig(msg.m_sLevel);
                if(!lConfig.has_value() || !lConfig.value().get().m_bLogToFile)
                    return std::nullopt;

                auto LogMsg = BuildMessage(msg.m_sLevel, msg.m_sLabel, msg.m_strMsg, msg.m_sourceLocation.function_name(), msg.m_sourceLocation.file_name(), msg.m_sourceLocation.line(), msg.m_backtrace, true);
                WriteToFile(g_fileObserver, LogMsg);
                
                return std::nullopt;
            });

            auto& logCraftConfig = GetLogCraftConfig();

            g_fileObserver.setRootPath(logCraftConfig.m_LogRootPath);
            g_fileObserver.setTrackerFilePath("log.track");
            g_fileObserver.setMaxSizeMB(logCraftConfig.m_nMaxSizeMB);
            g_fileObserver.setMaxFiles(logCraftConfig.m_nMaxFiles);
            g_fileObserver.setMaxAgeDays(logCraftConfig.m_nMaxAgeDays);

            g_fileObserver.open();

            g_threadPoolFile.setThreadCount(g_msgServerConfig.m_nMaxThreadsFile);
            g_threadPoolFile.start();
        }

        LC_API void StopMsgServer()
        {
            g_threadPoolConsole.stop();
            g_threadPoolFile.stop();
        }

        LC_API util::ThreadPool<LogMsg>& GetThreadPoolTerminal()
        {
            return g_threadPoolConsole;
        }

        LC_API util::ThreadPool<LogMsg>& GetThreadPoolFile()
        {
            return g_threadPoolFile;
        }

        LC_API FileObserver& GetFileObserver()
        {
            return g_fileObserver;
        }
    }

    LC_API void SetMaxThreadsTerminal(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreadsTerminal = nThreads;
    }

    LC_API void SetMaxThreadsFile(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreadsFile = nThreads;
    }
}