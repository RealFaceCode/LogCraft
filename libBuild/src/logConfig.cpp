#include "logConfig.hpp"

#include <unordered_map>
#include <ranges>
#include <algorithm>

#include "logCraftConfig.hpp"
namespace lc
{
    std::unordered_map<std::string, internal::LogConfig> g_logConfigMap;
    std::set<std::string> g_availableOrderTypes;
    
    namespace internal
    {
        std::pair<std::string, std::string> GetInfrontAndAfterTrim(std::string& s, std::string_view sTrim, std::string_view trimUntil)
        {   
            std::size_t pos = s.find(sTrim);
            if(pos == std::string::npos)
                return {"", ""};

            std::string infront = s.substr(0, pos);
            s.erase(0, pos + sTrim.size());

            std::string after;
            for(auto trim : trimUntil)
            {
                pos = s.find_first_of(trim) + 1;
                if(pos != std::string::npos)
                {
                    after = s.substr(0, pos);
                    for(auto order : g_availableOrderTypes)
                    {
                        if(after.find(order) != std::string::npos)
                        {
                            after = "";
                            pos = 0;
                        }
                    }
                    break;
                }
                else
                {
                    after = "";
                    break;
                }
            }
            s.erase(0, pos);

            return {infront, after};
        }

        LOGCRAFT_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                return it->second;
            return std::nullopt;
        }

        LOGCRAFT_API std::set<std::string>& GetAvailableOrders()
        {
            return g_availableOrderTypes;
        }

            LOGCRAFT_API void SetLogStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel)
        {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBLevel = sBLevel;
        }

        LOGCRAFT_API void SetLogStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBLabel = sBLabel;
        }

        LOGCRAFT_API void SetLogStringBeforeTime(std::string_view sLogType, std::string_view sBTime)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTime = sBTime;
        }   

        LOGCRAFT_API void SetLogStringBeforeDate(std::string_view sLogType, std::string_view sBDate)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBDate = sBDate;
        }

        LOGCRAFT_API void SetLogStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBFunction = sBFunction;
        }

        LOGCRAFT_API void SetLogStringBeforeLine(std::string_view sLogType, std::string_view sBLine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBLine = sBLine;
        }

        LOGCRAFT_API void SetLogStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBMessage = sBMessage;
        }

        LOGCRAFT_API void SetLogStringAfterLevel(std::string_view sLogType, std::string_view sALevel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALevel = sALevel;
        }

        LOGCRAFT_API void SetLogStringAfterLabel(std::string_view sLogType, std::string_view sALabel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALabel = sALabel;
        }

        LOGCRAFT_API void SetLogStringAfterTime(std::string_view sLogType, std::string_view sATime)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATime = sATime;
        }

        LOGCRAFT_API void SetLogStringAfterDate(std::string_view sLogType, std::string_view sADate)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sADate = sADate;
        }

        LOGCRAFT_API void SetLogStringAfterFunction(std::string_view sLogType, std::string_view sAFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sAFunction = sAFunction;
        }

        LOGCRAFT_API void SetLogStringAfterLine(std::string_view sLogType, std::string_view sALine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALine = sALine;
        }

        LOGCRAFT_API void SetLogStringAfterMessage(std::string_view sLogType, std::string_view sAMessage)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sAMessage = sAMessage;
        }

        LOGCRAFT_API void SetLogStringBeforeLevelToAll(std::string_view sBLevel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLevel = sBLevel;
        }

        LOGCRAFT_API void SetLogStringBeforeLabelToAll(std::string_view sBLabel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLabel = sBLabel;
        }

        LOGCRAFT_API void SetLogStringBeforeTimeToAll(std::string_view sBTime)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTime = sBTime;
        }

        LOGCRAFT_API void SetLogStringBeforeDateToAll(std::string_view sBDate)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBDate = sBDate;
        }

        LOGCRAFT_API void SetLogStringBeforeFunctionToAll(std::string_view sBFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBFunction = sBFunction;
        }

        LOGCRAFT_API void SetLogStringBeforeLineToAll(std::string_view sBLine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLine = sBLine;
        }

        LOGCRAFT_API void SetLogStringBeforeMessageToAll(std::string_view sBMessage)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBMessage = sBMessage;
        }

        LOGCRAFT_API void SetLogStringAfterLevelToAll(std::string_view sALevel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALevel = sALevel;
        }

        LOGCRAFT_API void SetLogStringAfterLabelToAll(std::string_view sALabel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALabel = sALabel;
        }

        LOGCRAFT_API void SetLogStringAfterTimeToAll(std::string_view sATime)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATime = sATime;
        }

        LOGCRAFT_API void SetLogStringAfterDateToAll(std::string_view sADate)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sADate = sADate;
        }

        LOGCRAFT_API void SetLogStringAfterFunctionToAll(std::string_view sAFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sAFunction = sAFunction;
        }

        LOGCRAFT_API void SetLogStringAfterLineToAll(std::string_view sALine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALine =sALine;
        }

        LOGCRAFT_API void SetLogStringAfterMessageToAll(std::string_view sAMessage)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sAMessage = sAMessage;
        }
    }

    LOGCRAFT_API bool AddLogType(std::string_view sLogType)
    {
        auto [it, succes] = g_logConfigMap.try_emplace(std::string(sLogType), internal::LogConfig());

        auto& lcConfig = internal::GetLogCraftConfig();

        if (lcConfig.m_nCurrentMaxLevelWidth < sLogType.size())
            lcConfig.m_nCurrentMaxLevelWidth = sLogType.size();

        return succes;
    }

    LOGCRAFT_API bool RemoveLogType(std::string_view sLogType)
    {
        return g_logConfigMap.erase(std::string(sLogType));
    }

    LOGCRAFT_API void SetWriteToFile(std::string_view sLogType, bool bLogToFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToFile = bLogToFile;
    }

    LOGCRAFT_API void SetWriteToFileToAll(bool bLogToFile)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToFile = bLogToFile;
    }

    LOGCRAFT_API void SetWriteToConsole(std::string_view sLogType, bool bLogToConsole)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToConsole = bLogToConsole;
    }

    LOGCRAFT_API void SetWriteToConsoleToAll(bool bLogToConsole)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToConsole = bLogToConsole;
    }

    LOGCRAFT_API void SetLogTime(std::string_view sLogType, bool bLogTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTime = bLogTime;
    }

    LOGCRAFT_API void SetLogTimeToAll(bool bLogTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogTime = bLogTime;
    }

    LOGCRAFT_API void SetLogDate(std::string_view sLogType, bool bLogDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogDate = bLogDate;
    }

    LOGCRAFT_API void SetLogDateToAll(bool bLogDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogDate = bLogDate;
    }

    LOGCRAFT_API void SetLogFunction(std::string_view sLogType, bool bLogFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFunction = bLogFunction;
    }

    LOGCRAFT_API void SetLogFunctionToAll(bool bLogFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogFunction = bLogFunction;
    }

    LOGCRAFT_API void SetLogLine(std::string_view sLogType, bool bLogLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLine = bLogLine;
    }

    LOGCRAFT_API void SetLogLineToAll(bool bLogLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLine = bLogLine;
    }

    LOGCRAFT_API void SetLogLevel(std::string_view sLogType, bool bLogLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLevel = bLogLevel;
    }

    LOGCRAFT_API void SetLogLevelToAll(bool bLogLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLevel = bLogLevel;
    }

    LOGCRAFT_API void SetLogMessage(std::string_view sLogType, bool bLogMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogMessage = bLogMessage;
    }

    LOGCRAFT_API void SetLogMessageToAll(bool bLogMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogMessage = bLogMessage;
    }

    LOGCRAFT_API void SetLogFilePath(std::string_view sLogType, std::string_view sLogFilePath)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogFilePath = std::string(sLogFilePath);
    }

    LOGCRAFT_API void SetLogTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogTimeFormat = std::string(sLogTimeFormat);
    }

    LOGCRAFT_API void SetLogDateFormat(std::string_view sLogType, std::string_view sLogDateFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogDateFormat = std::string(sLogDateFormat);
    }

    LOGCRAFT_API void SetLogColorLevel(std::string_view sLogType, bool bColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLevel = bColorLevel;
    }

    LOGCRAFT_API void SetLogColorLevelToAll(bool bColorLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLevel = bColorLevel;
    }

    LOGCRAFT_API void SetLogColorLabel(std::string_view sLogType, bool bColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLabel = bColorLabel;
    }

    LOGCRAFT_API void SetLogColorLabelToAll(bool bColorLabel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLabel = bColorLabel;
    }

    LOGCRAFT_API void SetLogColorTime(std::string_view sLogType, bool bColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTime = bColorTime;
    }

    LOGCRAFT_API void SetLogColorTimeToAll(bool bColorTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorTime = bColorTime;
    }

    LOGCRAFT_API void SetLogColorDate(std::string_view sLogType, bool bColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorDate = bColorDate;
    }

    LOGCRAFT_API void SetLogColorDateToAll(bool bColorDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorDate = bColorDate;
    }

    LOGCRAFT_API void SetLogColorFunction(std::string_view sLogType, bool bColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFunction = bColorFunction;
    }

    LOGCRAFT_API void SetLogColorFunctionToAll(bool bColorFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorFunction = bColorFunction;
    }

    LOGCRAFT_API void SetLogColorLine(std::string_view sLogType, bool bColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLine = bColorLine;
    }

    LOGCRAFT_API void SetLogColorLineToAll(bool bColorLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLine = bColorLine;
    }

    LOGCRAFT_API void SetLogColorMessage(std::string_view sLogType, bool bColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorMessage = bColorMessage;
    }

    LOGCRAFT_API void SetLogColorMessageToAll(bool bColorMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorMessage = bColorMessage;
    }

    LOGCRAFT_API void SetLogColorLevel(std::string_view sLogType, std::string_view sColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = std::string(sColorLevel);
    }

    LOGCRAFT_API void SetLogColorLabel(std::string_view sLogType, std::string_view sColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = std::string(sColorLabel);
    }

    LOGCRAFT_API void SetLogColorTime(std::string_view sLogType, std::string_view sColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = std::string(sColorTime);
    }

    LOGCRAFT_API void SetLogColorDate(std::string_view sLogType, std::string_view sColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = std::string(sColorDate);
    }

    LOGCRAFT_API void SetLogColorFunction(std::string_view sLogType, std::string_view sColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = std::string(sColorFunction);
    }

    LOGCRAFT_API void SetLogColorLine(std::string_view sLogType, std::string_view sColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = std::string(sColorLine);
    }

    LOGCRAFT_API void SetLogColorMessage(std::string_view sLogType, std::string_view sColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = std::string(sColorMessage);
    }

    LOGCRAFT_API void SetLogColorLevel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorLabel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorTime(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorDate(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorFunction(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorLine(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorMessage(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogOrder(std::string_view sLogType, std::vector<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_logOrder = logOrder;
    }

    LOGCRAFT_API void SetLogOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
        {
            it->second.m_logOrder.clear();
            it->second.m_logOrder.insert(it->second.m_logOrder.end(), logOrder.begin(), logOrder.end());
        }
    }

    LOGCRAFT_API void SetLogOrderToAll(std::vector<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_logOrder = logOrder;
    }

    LOGCRAFT_API void SetLogOrderToAll(std::initializer_list<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
        {
            value.m_logOrder.clear();
            value.m_logOrder.insert(value.m_logOrder.end(), logOrder.begin(), logOrder.end());
        }
    }

    LOGCRAFT_API void SetFormatTrim(std::string_view sLogType, std::string_view sFormatTrim)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sFormatTrim = sFormatTrim;
    }

    LOGCRAFT_API void SetFormatTrimToAll(std::string_view sFormatTrim)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sFormatTrim = sFormatTrim;
    }

    LOGCRAFT_API void SetFormat(std::string_view sLogType, std::string_view sFormat)
    {
        std::vector<std::pair<std::size_t, std::string>> indexPos;
        for(auto key : g_availableOrderTypes)
        {
            std::size_t pos = sFormat.find(key);
            if (pos != std::string::npos)
                indexPos.push_back({pos, key});
        }

        if(indexPos.empty())
            return;

        std::ranges::sort(indexPos, std::less<>());
        std::string format(sFormat);

        auto config = internal::GetLogConfig(sLogType);
        if(!config)
            return;

        auto trim = config->get().m_sFormatTrim;
        if(trim.empty())
            trim = "] ";

        std::vector<LogOrder> logOrder;

        for(auto pair : indexPos)
        {
            if(pair.second == "{LEVEL}")
            {
                SetLogLevel(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeLevel(sLogType, infront);
                internal::SetLogStringAfterLevel(sLogType, after);
                logOrder.emplace_back(LogOrder::Level);
            }
            else if(pair.second == "{LABEL}")
            {
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeLabel(sLogType, infront);
                internal::SetLogStringAfterLabel(sLogType, after);
                logOrder.emplace_back(LogOrder::Label);
            }
            else if(pair.second == "{TIME}")
            {
                SetLogTime(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeTime(sLogType, infront);
                internal::SetLogStringAfterTime(sLogType, after);
                logOrder.emplace_back(LogOrder::Time);
            }
            else if(pair.second == "{DATE}")
            {
                SetLogDate(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeDate(sLogType, infront);
                internal::SetLogStringAfterDate(sLogType, after);
                logOrder.emplace_back(LogOrder::Date);
            }
            else if(pair.second == "{FUNC}")
            {
                SetLogFunction(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeFunction(sLogType, infront);
                internal::SetLogStringAfterFunction(sLogType, after);
                logOrder.emplace_back(LogOrder::Function);
            }
            else if(pair.second == "{LINE}")
            {
                SetLogLine(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeLine(sLogType, infront);
                internal::SetLogStringAfterLine(sLogType, after);
                logOrder.emplace_back(LogOrder::Line);
            }
            else if(pair.second == "{MSG}")
            {
                SetLogMessage(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeMessage(sLogType, infront);
                internal::SetLogStringAfterMessage(sLogType, after);
                logOrder.emplace_back(LogOrder::Message);
            }
        }

        SetLogOrder(sLogType, logOrder);
    }

    LOGCRAFT_API void SetFormatToAll(std::string_view sFormat)
    {
        for(auto& [key, value] : g_logConfigMap)
            SetFormat(key, sFormat);
    }
}