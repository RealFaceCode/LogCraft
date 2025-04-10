#include "logcraft/logcraftConfig.hpp"

namespace lc
{
    namespace internal
    {
        LogCraftConfig g_logCraftConfig;

        LC_API LogCraftConfig& GetLogCraftConfig()
        {
            return g_logCraftConfig;
        }
    }

    LC_API void SetAllignLevel(bool bAllignLeft)
    {
        internal::g_logCraftConfig.m_bAllignLeft = bAllignLeft;
    }

    LC_API void SetMaxLevelWidth(std::size_t nWidth)
    {
        internal::g_logCraftConfig.m_nCurrentMaxLevelWidth = nWidth;
    }

    LC_API void SetLogRootPath(const std::filesystem::path& path)
    {
        internal::g_logCraftConfig.m_LogRootPath = path;
    }

    LC_API void SetMaxSizeMB(std::size_t nMaxSizeMB)
    {
        internal::g_logCraftConfig.m_nMaxSizeMB = nMaxSizeMB;
    }

    LC_API void SetMaxFiles(std::size_t nMaxFiles)
    {
        internal::g_logCraftConfig.m_nMaxFiles = nMaxFiles;
    }

    LC_API void SetMaxAgeDays(std::size_t nMaxAgeDays)
    {
        internal::g_logCraftConfig.m_nMaxAgeDays = nMaxAgeDays;
    }
}