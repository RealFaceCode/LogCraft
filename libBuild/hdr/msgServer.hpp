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
            std::size_t m_nMaxThreads = 2;
        };

        LOGCRAFT_API void SartMsgServer();
        LOGCRAFT_API void StopMsgServer();

        eutil::ThreadPool<LogMsg>& LOGCRAFT_API GetThreadPool();
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads);
}