#include "logConfig.hpp"
#include <unordered_map>

namespace lc
{
    std::unordered_map<std::string, internal::LogConfig> g_logConfigMap;
    
    namespace internal
    {
        std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType)
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

    void SetLogTypeColorLevel(std::string_view sLogType, bool bColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLevel = bColorLevel;
    }

    void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTime = bColorTime;
    }

    void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorDate = bColorDate;
    }

    void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFunction = bColorFunction;
    }

    void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLine = bColorLine;
    }

    void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorMessage = bColorMessage;
    }

    void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = std::string(sColorLevel);
    }

    void SetLogTypeColorTime(std::string_view sLogType, std::string_view sColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = std::string(sColorTime);
    }

    void SetLogTypeColorDate(std::string_view sLogType, std::string_view sColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = std::string(sColorDate);
    }

    void SetLogTypeColorFunction(std::string_view sLogType, std::string_view sColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = std::string(sColorFunction);
    }

    void SetLogTypeColorLine(std::string_view sLogType, std::string_view sColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = std::string(sColorLine);
    }

    void SetLogTypeColorMessage(std::string_view sLogType, std::string_view sColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = std::string(sColorMessage);
    }

    void SetLogTypeOrder(std::string_view sLogType, std::queue<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_logOrder = logOrder;
    }

    void SetLogTypeOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            for (const auto& order : logOrder)
                it->second.m_logOrder.push(order);
    }
}