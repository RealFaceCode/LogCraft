#include "msgServer.hpp"

#include <memory>

#include "write.hpp"
#include "logConfig.hpp"
#include "file.hpp"
#include "logcraftConfig.hpp"

namespace lc
{
    namespace internal
    {
        MsgServerConfig g_msgServerConfig;
        eutil::ThreadPool<LogMsg> g_threadPoolConsole;
        eutil::ThreadPool<LogMsg> g_threadPoolFile;
        eutil::File g_ConfigFile;
        eutil::File g_LogFile;

        LC_API void SartMsgServer()
        {
            g_threadPoolConsole.setTaskFunc([](const LogMsg& msg) -> std::optional<int>
            {
                const auto& lConfig = GetLogConfig(msg.m_sLevel);
                if(!lConfig.has_value() || !lConfig.value().get().m_bLogToConsole)
                    return std::nullopt;

                auto LogMsg = BuildMessage(msg.m_sLevel, msg.m_sLabel, msg.m_strMsg, msg.m_sourceLocation.function_name(), msg.m_sourceLocation.file_name(), msg.m_sourceLocation.line());
                WriteToConsole(LogMsg);

                return std::nullopt;
            });

            g_threadPoolConsole.setThreadCount(g_msgServerConfig.m_nMaxThreads);
            g_threadPoolConsole.start();

            g_threadPoolFile.setTaskFunc([](const LogMsg& msg) -> std::optional<int>
            {
                const auto& lConfig = GetLogConfig(msg.m_sLevel);
                if(!lConfig.has_value() || !lConfig.value().get().m_bLogToFile)
                    return std::nullopt;

                auto LogMsg = BuildMessage(msg.m_sLevel, msg.m_sLabel, msg.m_strMsg, msg.m_sourceLocation.function_name(), msg.m_sourceLocation.file_name(), msg.m_sourceLocation.line(), true);
                WriteToFile(LogMsg);
                
                return std::nullopt;
            });

            auto& logCraftConfig = GetLogCraftConfig();

            eutil::CreateDirectory(logCraftConfig.m_LogRootPath);

            std::filesystem::path configPath = logCraftConfig.m_LogRootPath;
            configPath /= "config.log";
            g_ConfigFile.open();

            g_threadPoolFile.setThreadCount(g_msgServerConfig.m_nMaxThreads);
            g_threadPoolFile.start();
        }

        LC_API void StopMsgServer()
        {
            g_threadPoolConsole.stop();
            g_threadPoolFile.stop();
        }

        LC_API eutil::ThreadPool<LogMsg>& GetThreadPool()
        {
            return g_threadPoolConsole;
        }
    }

    LC_API void SetMaxThreads(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreads = nThreads;
    }
}