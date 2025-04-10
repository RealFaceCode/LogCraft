#pragma once

#include "defines.hpp"
#include <filesystem>
#include <vector>

namespace lc
{
    /**
     * @brief Observes and manages log files.
     * 
     * @note This struct handles the creation, writing, and management of log files.
     */
    struct LC_API FileObserver
    {
    public:
        FileObserver() = default;
        /**
         * @brief Constructs a FileObserver with specified parameters.
         * 
         * @param rootPath The root path for log files.
         * @param trackerFilePath The path for the tracker file.
         * @param nMaxSizeMB The maximum size of a log file in MB.
         * @param nMaxFiles The maximum number of log files.
         * @param nMaxAgeDays The maximum age of log files in days.
         */
        FileObserver(const std::filesystem::path& rootPath, const std::filesystem::path& trackerFilePath, std::size_t nMaxSizeMB, std::size_t nMaxFiles, std::size_t nMaxAgeDays);
        ~FileObserver() = default;

        /**
         * @brief Opens the current log file.
         */
        void open();
        /**
         * @brief Writes data to the current log file.
         * 
         * @param data The data to be written.
         * @param size The size of the data.
         */
        void write(const void* data, std::size_t size);
        /**
         * @brief Closes the current log file.
         */
        void close();

        /**
         * @brief Sets the root path for log files.
         * 
         * @param rootPath The root path.
         */
        void setRootPath(const std::filesystem::path& rootPath);
        /**
         * @brief Sets the path for the tracker file.
         * 
         * @param trackerFilePath The tracker file path.
         */
        void setTrackerFilePath(const std::filesystem::path& trackerFilePath);
        /**
         * @brief Sets the maximum size of a log file in MB.
         * 
         * @param nMaxSizeMB The maximum size in MB.
         */
        void setMaxSizeMB(std::size_t nMaxSizeMB);
        /**
         * @brief Sets the maximum number of log files.
         * 
         * @param nMaxFiles The maximum number of files.
         */
        void setMaxFiles(std::size_t nMaxFiles);
        /**
         * @brief Sets the maximum age of log files in days.
         * 
         * @param nMaxAgeDays The maximum age in days.
         */
        void setMaxAgeDays(std::size_t nMaxAgeDays);

    private:
        /**
         * @brief Checks if the active file has reached its maximum size.
         * 
         * @return true if the maximum size is reached, false otherwise.
         */
        bool hasActiveFileMaxSizeReached() const;
        /**
         * @brief Switches to a new active log file.
         */
        void switchActiveFile();

        std::filesystem::path m_rootPath;
        std::filesystem::path m_trackerFilePath;
        std::filesystem::path m_activeFilePath;
        std::vector<std::filesystem::path> m_files;
        std::size_t m_nMaxSizeMB = 0;
        std::size_t m_nMaxFiles = 0;
        std::size_t m_nMaxAgeDays = 0;
        FILE* m_trackerFile;
        FILE* m_currentFile;
    };
}