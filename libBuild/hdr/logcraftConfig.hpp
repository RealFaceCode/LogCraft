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
            bool m_bAllignLeft                  = true;
            std::filesystem::path m_LogRootPath = "logs";
            std::size_t m_nMaxSizeMB            = 1;
            std::size_t m_nMaxFiles             = 5;
            std::size_t m_nMaxAgeDays           = 5;
        };

        LC_API LogCraftConfig& GetLogCraftConfig();
    }   

    LC_API void SetAllignLevel(bool bAllignLeft);
    LC_API void SetMaxLevelWidth(std::size_t nWidth);
    LC_API void SetLogRootPath(const std::filesystem::path& path);
    LC_API void SetMaxSizeMB(std::size_t nMaxSizeMB);
    LC_API void SetMaxFiles(std::size_t nMaxFiles);
    LC_API void SetMaxAgeDays(std::size_t nMaxAgeDays);
}