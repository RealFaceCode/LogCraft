#pragma once

#include <memory>

#include "defines.hpp"

namespace lc
{
    namespace internal
    {
        struct LC_API LogCraftConfig
        {
            std::size_t m_nCurrentMaxLevelWidth = 0;
            bool m_bAllignLeft = true;
        };

        LC_API LogCraftConfig& GetLogCraftConfig();
    }   

    LC_API void SetAllignLevel(bool bAllignLeft);
    LC_API void SetMaxLevelWidth(std::size_t nWidth);
}