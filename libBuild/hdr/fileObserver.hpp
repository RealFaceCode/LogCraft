#pragma once

#include "defines.hpp"
#include <filesystem>
#include <vector>
#include "file.hpp"

namespace lc
{
    struct LC_API FileObserver
    {
    public:
        FileObserver() = default;
        FileObserver(const std::filesystem::path& rootPath, const std::filesystem::path& trackerFilePath, std::size_t nMaxSizeMB, std::size_t nMaxFiles, std::size_t nMaxAgeDays);
        ~FileObserver() = default;

        void open();
        void write(const void* data, std::size_t size);
        void close();

        void setRootPath(const std::filesystem::path& rootPath);
        void setTrackerFilePath(const std::filesystem::path& trackerFilePath);
        void setMaxSizeMB(std::size_t nMaxSizeMB);
        void setMaxFiles(std::size_t nMaxFiles);
        void setMaxAgeDays(std::size_t nMaxAgeDays);

    private:
        bool hasActiveFileMaxSizeReached() const;
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