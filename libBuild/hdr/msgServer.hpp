#pragma once

#include <cstdint>

#include "threadPool.hpp"
#include "defines.hpp"
#include "logMsg.hpp"

namespace lc
{
    namespace internal
    {
        struct LOGCRAFT_API MsgServerConfig
        {
            std::size_t m_nMaxThreads = 0;
        };

        LOGCRAFT_API void SartMsgServer();
        LOGCRAFT_API void StopMsgServer();

        std::shared_ptr<eutil::ThreadPool<LogMsg>> LOGCRAFT_API GetThreadPool();
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads);
}