#pragma once

#include <cstdint>

#include "threadPool.hpp"
#include "defines.hpp"
#include "logMsg.hpp"

namespace lc
{

    struct FileObserver;

    namespace internal
    {
        struct LC_API MsgServerConfig
        {
            std::size_t m_nMaxThreadsTerminal   = 2;
            std::size_t m_nMaxThreadsFile       = 1;
        };

        LC_API void SartMsgServer();
        LC_API void StopMsgServer();

        LC_API eutil::ThreadPool<LogMsg>& GetThreadPoolTerminal();
        LC_API eutil::ThreadPool<LogMsg>& GetThreadPoolFile();
        LC_API FileObserver& GetFileObserver();
    }

    LC_API void SetMaxThreadsTerminal(std::size_t nThreads);
    LC_API void SetMaxThreadsFile(std::size_t nThreads);
}