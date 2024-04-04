#include "msgServer.hpp"

#include <memory>

#include "write.hpp"

namespace lc
{
    namespace internal
    {
        MsgServerConfig g_msgServerConfig;
        eutil::ThreadPool<LogMsg> g_threadPool;

        LOGCRAFT_API void SartMsgServer()
        {
            g_threadPool.setTaskFunc([](const LogMsg& msg) -> std::optional<int>
            {
                auto LogMsg = BuildMessage(msg.m_sLevel, msg.m_sLabel, msg.m_strMsg, msg.m_sourceLocation.function_name(), msg.m_sourceLocation.file_name(), msg.m_sourceLocation.line());
                WriteToConsole(LogMsg);
                return std::nullopt;
            });

            g_threadPool.setThreadCount(g_msgServerConfig.m_nMaxThreads);
            g_threadPool.start();
        }

        LOGCRAFT_API void StopMsgServer()
        {
                g_threadPool.stop();
        }

        eutil::ThreadPool<LogMsg>& LOGCRAFT_API GetThreadPool()
        {
            return g_threadPool;
        }
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreads = nThreads;
    }
}