#pragma once

#include <memory>
#include <filesystem>

#include "defines.hpp"

namespace lc
{
    namespace internal
    {
        /** 
         * @brief Configuration for LogCraft
         * 
         * @note Includes settings for log file management and formatting.
         */
        struct LC_API LogCraftConfig
        {
            std::size_t m_nCurrentMaxLevelWidth = 0;
            bool m_bAllignLeft                  = true;
            std::filesystem::path m_LogRootPath = "logs";
            std::size_t m_nMaxSizeMB            = 1;
            std::size_t m_nMaxFiles             = 5;
            std::size_t m_nMaxAgeDays           = 5;
        };

        /** 
         * @brief Get the LogCraft configuration
         * 
         * @note Returns a reference to the current configuration.
         */
        LC_API LogCraftConfig& GetLogCraftConfig();
    }   

    /** 
     * @brief Set alignment for log levels
     * 
     * @note Determines whether log levels are aligned to the left.
     */
    LC_API void SetAllignLevel(bool bAllignLeft);

    /** 
     * @brief Set maximum width for log levels
     * 
     * @note Adjusts the width used for displaying log levels.
     */
    LC_API void SetMaxLevelWidth(std::size_t nWidth);

    /** 
     * @brief Set the root path for log files
     * 
     * @note Specifies the directory where log files are stored.
     */
    LC_API void SetLogRootPath(const std::filesystem::path& path);

    /** 
     * @brief Set maximum size for log files
     * 
     * @note Defines the maximum size (in MB) for individual log files.
     */
    LC_API void SetMaxSizeMB(std::size_t nMaxSizeMB);

    /** 
     * @brief Set maximum number of log files
     * 
     * @note Limits the number of log files to retain.
     */
    LC_API void SetMaxFiles(std::size_t nMaxFiles);

    /** 
     * @brief Set maximum age for log files
     * 
     * @note Specifies the maximum age (in days) for log files before they are deleted.
     */
    LC_API void SetMaxAgeDays(std::size_t nMaxAgeDays);
}