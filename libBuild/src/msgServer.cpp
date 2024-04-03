#include "msgServer.hpp"

#include <memory>

#include "hdr/ThreadPool.hpp"

namespace lc
{
    namespace internal
    {
        MsgServerConfig g_msgServerConfig;
        std::shared_ptr<eutil::ThreadPool<std::string>> g_threadPool = nullptr; //TODO: write a specific struct for msgs

        LOGCRAFT_API void SartMsgServer()
        {
            if(!g_threadPool)
                g_threadPool = std::make_shared<eutil::ThreadPool<std::string>>([](const std::string& data) -> std::optional<int> 
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
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads)
    {
        internal::g_msgServerConfig.m_nMaxThreads = nThreads;
    }
}