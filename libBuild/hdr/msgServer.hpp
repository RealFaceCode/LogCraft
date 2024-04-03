#pragma once

#include <cstdint>

#include "defines.hpp"

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
    }

    LOGCRAFT_API void SetMaxThreads(std::size_t nThreads);
}