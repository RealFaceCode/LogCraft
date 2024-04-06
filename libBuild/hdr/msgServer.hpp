#pragma once

#include <cstdint>

#include "threadPool.hpp"
#include "defines.hpp"
#include "logMsg.hpp"

namespace lc
{
    namespace internal
    {
        struct LC_API MsgServerConfig
        {
            std::size_t m_nMaxThreads = 2;
        };

        LC_API void SartMsgServer();
        LC_API void StopMsgServer();

        LC_API eutil::ThreadPool<LogMsg>& GetThreadPool();
    }

    LC_API void SetMaxThreads(std::size_t nThreads);
}