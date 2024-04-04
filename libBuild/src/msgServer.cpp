#include "msgServer.hpp"

#include <memory>

namespace lc
{
    namespace internal
    {
        MsgServerConfig g_msgServerConfig;
        std::shared_ptr<eutil::ThreadPool<LogMsg>> g_threadPool = nullptr;

        LOGCRAFT_API void SartMsgServer()
        {
            if(!g_threadPool)
                g_threadPool = std::make_shared<eutil::ThreadPool<LogMsg>>([](const LogMsg& data) -> std::optional<int> 
                {
                    return std::nullopt;
                }, g_msgServerConfig.m_nMaxThreads);

            g_threadPool->start();
        }

        LOGCRAFT_API void StopMsgServer()
        {
            if(g_threadPool)
                g_threadPool->stop();
        }

        std::shared_ptr<eutil::ThreadPool<LogMsg>> LOGCRAFT_API GetThreadPool()
        {
            return g_threadPool;
        }
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreads = nThreads;
    }
}