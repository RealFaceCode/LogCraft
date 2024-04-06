#pragma once

#include <memory>
#include <filesystem>

#include "defines.hpp"

namespace lc
{
    namespace internal
    {
        struct LC_API LogCraftConfig
        {
            std::size_t m_nCurrentMaxLevelWidth = 0;
            bool m_bAllignLeft = true;
            std::filesystem::path m_LogRootPath = "logs";
        };

        LC_API LogCraftConfig& GetLogCraftConfig();
    }   

    LC_API void SetAllignLevel(bool bAllignLeft);
    LC_API void SetMaxLevelWidth(std::size_t nWidth);
    LC_API void SetLogRootPath(const std::filesystem::path& path);
}