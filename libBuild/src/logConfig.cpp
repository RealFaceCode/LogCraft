#include "logConfig.hpp"
#include <unordered_map>

namespace lc
{
    std::unordered_map<std::string, internal::LogConfig> g_logConfigMap;
    
    namespace internal
    {
        std::optional<const LogConfig&> GetLogConfig(std::string_view sLogType)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                return it->second;
            return std::nullopt;
        }
    }

    bool AddLogType(std::string_view sLogType)
    {
        auto [it, succes] = g_logConfigMap.try_emplace(std::string(sLogType), internal::LogConfig());
        return succes;
    }

    bool RemoveLogType(std::string_view sLogType)
    {
        return g_logConfigMap.erase(std::string(sLogType));
    }

    void SetLogTypeToFile(std::string_view sLogType, bool bLogToFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToFile = bLogToFile;
    }

    void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToConsole = bLogToConsole;
    }

    void SetLogTypeTime(std::string_view sLogType, bool bLogTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTime = bLogTime;
    }

    void SetLogTypeDate(std::string_view sLogType, bool bLogDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogDate = bLogDate;
    }

    void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFunction = bLogFunction;
    }

    void SetLogTypeLine(std::string_view sLogType, bool bLogLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLine = bLogLine;
    }

    void SetLogTypeLevel(std::string_view sLogType, bool bLogLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLevel = bLogLevel;
    }

    void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogMessage = bLogMessage;
    }

    void SetLogTypeFilePath(std::string_view sLogType, std::string_view sLogFilePath)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogFilePath = std::string(sLogFilePath);
    }

    void SetLogTypeTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogTimeFormat = std::string(sLogTimeFormat);
    }

    void SetLogTypeDateFormat(std::string_view sLogType, std::string_view sLogDateFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogDateFormat = std::string(sLogDateFormat);
    }
}