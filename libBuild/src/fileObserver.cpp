#include "fileObserver.hpp"

#include "file.hpp"
#include "util.hpp"
#include <print>
#include <filesystem>
#include <string>

namespace lc
{
    LC_API FileObserver::FileObserver(const std::filesystem::path& rootPath, const std::filesystem::path& trackerFilePath, std::size_t nMaxSizeMB, std::size_t nMaxFiles, std::size_t nMaxAgeDays)
    : m_rootPath(rootPath), m_trackerFilePath(trackerFilePath), m_nMaxSizeMB(nMaxSizeMB), m_nMaxFiles(nMaxFiles), m_nMaxAgeDays(nMaxAgeDays)
    {}

    LC_API void FileObserver::open()
    {
        if(!eutil::FileExists(m_rootPath))
            eutil::CreateDirectory(m_rootPath);

        m_trackerFilePath = m_rootPath / m_trackerFilePath;

        if(!eutil::FileExists(m_trackerFilePath))
            eutil::CreateFile(m_trackerFilePath);

        fopen_s(&m_trackerFile, m_trackerFilePath.string().c_str(), "r+");
        fseek(m_trackerFile, 0, SEEK_END);
        auto size = ftell(m_trackerFile);
        fseek(m_trackerFile, 0, SEEK_SET);

        std::vector<uint8_t> buffer(size);
        fread(buffer.data(), 1, size, m_trackerFile);
        uint64_t offset = 0;

        if(size != 0)
        {
            uint64_t count;
            memcpy(&count, buffer.data(), sizeof(uint64_t));
            offset += sizeof(uint64_t);

            for(size_t i = 0; i < count; ++i)
            {
                uint64_t len;
                memcpy(&len, buffer.data() + offset, sizeof(uint64_t));
                offset += sizeof(uint64_t);
                std::string path;
                path.resize(len);

                memcpy(path.data(), buffer.data() + offset, len);
                offset += len;

                m_files.push_back(path);
            }

            if(eutil::FileExists(m_files.back()))
            {
                m_activeFilePath = m_files.back();
                fopen_s(&m_currentFile, m_activeFilePath.string().c_str(), "a");
                switchActiveFile();
            }
        }
        else
        {
            std::string fileName = "log";
            fileName.append(eutil::getCurrentTime("%Y%m%d_%H%M%S"));
            fileName.append(".log");
            m_activeFilePath = m_rootPath / fileName;

            if(eutil::CreateFile(m_activeFilePath))
            {
                m_files.push_back(m_activeFilePath);
                fopen_s(&m_currentFile, m_activeFilePath.string().c_str(), "a");
            }
        }

        fclose(m_trackerFile);
    }

    LC_API void FileObserver::write(const void* data, std::size_t size)
    {
        if(m_currentFile)
        {
            switchActiveFile();
            fwrite(data, 1, size, m_currentFile);
        }
    }

    LC_API void FileObserver::close()
    {
        fopen_s(&m_trackerFile, m_trackerFilePath.string().c_str(), "w");
        uint64_t count = m_files.size();
        fwrite(&count, sizeof(uint64_t), 1, m_trackerFile);

        for(const auto& file : m_files)
        {
            uint64_t len = file.string().size();
            fwrite(&len, sizeof(uint64_t), 1, m_trackerFile);
            fwrite(file.string().c_str(), len, 1, m_trackerFile);
        }

        fflush(m_trackerFile);  
        fclose(m_currentFile);
    }

    LC_API void FileObserver::setRootPath(const std::filesystem::path& rootPath)
    {
        m_rootPath = rootPath;
    }

    LC_API void FileObserver::setTrackerFilePath(const std::filesystem::path& trackerFilePath)
    {
        m_trackerFilePath = trackerFilePath;
    }

    LC_API void FileObserver::setMaxSizeMB(std::size_t nMaxSizeMB)
    {
        m_nMaxSizeMB = nMaxSizeMB;
    }

    LC_API void FileObserver::setMaxFiles(std::size_t nMaxFiles)
    {
        m_nMaxFiles = nMaxFiles;
    }

    LC_API void FileObserver::setMaxAgeDays(std::size_t nMaxAgeDays)
    {
        m_nMaxAgeDays = nMaxAgeDays;
    }

    LC_API bool FileObserver::hasActiveFileMaxSizeReached() const
    {
        if(m_nMaxSizeMB == 0)
            return false;

        if(!eutil::FileExists(m_activeFilePath))
            return false;

        return std::filesystem::file_size(m_activeFilePath) >= m_nMaxSizeMB * 1024 * 1024;
    }

    LC_API void FileObserver::switchActiveFile()
    {
        if(m_files.empty())
            return;

        if(!hasActiveFileMaxSizeReached())
            return;

        fclose(m_currentFile);
        m_currentFile = nullptr;

        if(m_files.size() >= m_nMaxFiles)
        {
            std::filesystem::remove(m_files.front());
            m_files.erase(m_files.begin());
        }

        std::string fileName = "log";
        fileName.append(eutil::getCurrentTime("%Y%m%d_%H%M%S"));
        fileName.append(".log");
        m_activeFilePath = m_rootPath / fileName;

        m_files.push_back(m_activeFilePath.string());
        eutil::CreateFile(m_activeFilePath);
        fopen_s(&m_currentFile, m_activeFilePath.string().c_str(), "a");
    }
}