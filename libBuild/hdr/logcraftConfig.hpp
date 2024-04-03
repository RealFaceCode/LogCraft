#pragma once

#include <memory>

#include "defines.hpp"

namespace lc
{
    namespace internal
    {
        struct LOGCRAFT_API LogCraftConfig
        {
            std::size_t m_nCurrentMaxLevelWidth = 0;
            bool m_bAllignLeft = true;
        };

        LOGCRAFT_API LogCraftConfig& GetLogCraftConfig();
    }   

    LOGCRAFT_API void SetAllignLevel(bool bAllignLeft);
    LOGCRAFT_API void SetMaxLevelWidth(std::size_t nWidth);
}