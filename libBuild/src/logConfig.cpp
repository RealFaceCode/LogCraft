#include "logConfig.hpp"
#include <unordered_map>

namespace lc
{
    std::unordered_map<std::string, internal::LogConfig> g_logConfigMap;
    
    namespace internal
    {
        LOGCRAFT_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                return it->second;
            return std::nullopt;
        }
    }

    LOGCRAFT_API bool AddLogType(std::string_view sLogType)
    {
        auto [it, succes] = g_logConfigMap.try_emplace(std::string(sLogType), internal::LogConfig());
        return succes;
    }

    LOGCRAFT_API bool RemoveLogType(std::string_view sLogType)
    {
        return g_logConfigMap.erase(std::string(sLogType));
    }

    LOGCRAFT_API void SetLogTypeToFile(std::string_view sLogType, bool bLogToFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToFile = bLogToFile;
    }

    LOGCRAFT_API void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToConsole = bLogToConsole;
    }

    LOGCRAFT_API void SetLogTypeTime(std::string_view sLogType, bool bLogTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTime = bLogTime;
    }

    LOGCRAFT_API void SetLogTypeDate(std::string_view sLogType, bool bLogDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogDate = bLogDate;
    }

    LOGCRAFT_API void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFunction = bLogFunction;
    }

    LOGCRAFT_API void SetLogTypeLine(std::string_view sLogType, bool bLogLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLine = bLogLine;
    }

    LOGCRAFT_API void SetLogTypeLevel(std::string_view sLogType, bool bLogLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLevel = bLogLevel;
    }

    LOGCRAFT_API void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogMessage = bLogMessage;
    }

    LOGCRAFT_API void SetLogTypeFilePath(std::string_view sLogType, std::string_view sLogFilePath)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogFilePath = std::string(sLogFilePath);
    }

    LOGCRAFT_API void SetLogTypeTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogTimeFormat = std::string(sLogTimeFormat);
    }

    LOGCRAFT_API void SetLogTypeDateFormat(std::string_view sLogType, std::string_view sLogDateFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogDateFormat = std::string(sLogDateFormat);
    }

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, bool bColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLevel = bColorLevel;
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTime = bColorTime;
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorDate = bColorDate;
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFunction = bColorFunction;
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLine = bColorLine;
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorMessage = bColorMessage;
    }

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = std::string(sColorLevel);
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, std::string_view sColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = std::string(sColorTime);
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, std::string_view sColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = std::string(sColorDate);
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, std::string_view sColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = std::string(sColorFunction);
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, std::string_view sColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = std::string(sColorLine);
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, std::string_view sColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = std::string(sColorMessage);
    }

    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::vector<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_logOrder = logOrder;
    }

    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
        {
            it->second.m_logOrder.clear();
            it->second.m_logOrder.insert(it->second.m_logOrder.end(), logOrder.begin(), logOrder.end());
            
        }
            
    }
}