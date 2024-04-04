#include "logConfig.hpp"
#include <unordered_map>

#include "logCraftConfig.hpp"

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

        auto& lcConfig = internal::GetLogCraftConfig();

        if (lcConfig.m_nCurrentMaxLevelWidth < sLogType.size())
            lcConfig.m_nCurrentMaxLevelWidth = sLogType.size();

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

    LOGCRAFT_API void SetLogTypeToFileToAll(bool bLogToFile)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToFile = bLogToFile;
    }

    LOGCRAFT_API void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToConsole = bLogToConsole;
    }

    LOGCRAFT_API void SetLogTypeToConsoleToAll(bool bLogToConsole)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToConsole = bLogToConsole;
    }

    LOGCRAFT_API void SetLogTypeTime(std::string_view sLogType, bool bLogTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTime = bLogTime;
    }

    LOGCRAFT_API void SetLogTypeTimeToAll(bool bLogTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogTime = bLogTime;
    }

    LOGCRAFT_API void SetLogTypeDate(std::string_view sLogType, bool bLogDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogDate = bLogDate;
    }

    LOGCRAFT_API void SetLogTypeDateToAll(bool bLogDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogDate = bLogDate;
    }

    LOGCRAFT_API void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFunction = bLogFunction;
    }

    LOGCRAFT_API void SetLogTypeFunctionToAll(bool bLogFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogFunction = bLogFunction;
    }

    LOGCRAFT_API void SetLogTypeLine(std::string_view sLogType, bool bLogLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLine = bLogLine;
    }

    LOGCRAFT_API void SetLogTypeLineToAll(bool bLogLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLine = bLogLine;
    }

    LOGCRAFT_API void SetLogTypeLevel(std::string_view sLogType, bool bLogLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLevel = bLogLevel;
    }

    LOGCRAFT_API void SetLogTypeLevelToAll(bool bLogLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLevel = bLogLevel;
    }

    LOGCRAFT_API void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogMessage = bLogMessage;
    }

    LOGCRAFT_API void SetLogTypeMessageToAll(bool bLogMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogMessage = bLogMessage;
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

    LOGCRAFT_API void SetLogTypeColorLevelToAll(bool bColorLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLevel = bColorLevel;
    }

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, bool bColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLabel = bColorLabel;
    }

    LOGCRAFT_API void SetLogTypeColorLabelToAll(bool bColorLabel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLabel = bColorLabel;
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTime = bColorTime;
    }

    LOGCRAFT_API void SetLogTypeColorTimeToAll(bool bColorTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorTime = bColorTime;
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorDate = bColorDate;
    }

    LOGCRAFT_API void SetLogTypeColorDateToAll(bool bColorDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorDate = bColorDate;
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFunction = bColorFunction;
    }

    LOGCRAFT_API void SetLogTypeColorFunctionToAll(bool bColorFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorFunction = bColorFunction;
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLine = bColorLine;
    }

    LOGCRAFT_API void SetLogTypeColorLineToAll(bool bColorLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLine = bColorLine;
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorMessage = bColorMessage;
    }

    LOGCRAFT_API void SetLogTypeColorMessageToAll(bool bColorMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorMessage = bColorMessage;
    }

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = std::string(sColorLevel);
    }

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, std::string_view sColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = std::string(sColorLabel);
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

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetColor(color);
    }

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetEffects(effects);
    }

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetEffects(effects);
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

    LOGCRAFT_API void SetLogTypeOrderToAll(std::vector<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_logOrder = logOrder;
    }

    LOGCRAFT_API void SetLogTypeOrderToAll(std::initializer_list<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
        {
            value.m_logOrder.clear();
            value.m_logOrder.insert(value.m_logOrder.end(), logOrder.begin(), logOrder.end());
        }
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBLevel = sBLevel;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBLabel = sBLabel;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeTime(std::string_view sLogType, std::string_view sBTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBTime = sBTime;
    }   

    LOGCRAFT_API void SetLogTypeStringBeforeDate(std::string_view sLogType, std::string_view sBDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBDate = sBDate;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBFunction = sBFunction;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLine(std::string_view sLogType, std::string_view sBLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBLine = sBLine;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sBMessage = sBMessage;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLevel(std::string_view sLogType, std::string_view sALevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sALevel = sALevel;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLabel(std::string_view sLogType, std::string_view sALabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sALabel = sALabel;
    }

    LOGCRAFT_API void SetLogTypeStringAfterTime(std::string_view sLogType, std::string_view sATime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sATime = sATime;
    }

    LOGCRAFT_API void SetLogTypeStringAfterDate(std::string_view sLogType, std::string_view sADate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sADate = sADate;
    }

    LOGCRAFT_API void SetLogTypeStringAfterFunction(std::string_view sLogType, std::string_view sAFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sAFunction = sAFunction;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLine(std::string_view sLogType, std::string_view sALine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sALine = sALine;
    }

    LOGCRAFT_API void SetLogTypeStringAfterMessage(std::string_view sLogType, std::string_view sAMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sAMessage = sAMessage;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLevelToAll(std::string_view sBLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBLevel = sBLevel;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLabelToAll(std::string_view sBLabel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBLabel = sBLabel;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeTimeToAll(std::string_view sBTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBTime = sBTime;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeDateToAll(std::string_view sBDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBDate = sBDate;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeFunctionToAll(std::string_view sBFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBFunction = sBFunction;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeLineToAll(std::string_view sBLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBLine = sBLine;
    }

    LOGCRAFT_API void SetLogTypeStringBeforeMessageToAll(std::string_view sBMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sBMessage = sBMessage;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLevelToAll(std::string_view sALevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sALevel = sALevel;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLabelToAll(std::string_view sALabel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sALabel = sALabel;
    }

    LOGCRAFT_API void SetLogTypeStringAfterTimeToAll(std::string_view sATime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sATime = sATime;
    }

    LOGCRAFT_API void SetLogTypeStringAfterDateToAll(std::string_view sADate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sADate = sADate;
    }

    LOGCRAFT_API void SetLogTypeStringAfterFunctionToAll(std::string_view sAFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sAFunction = sAFunction;
    }

    LOGCRAFT_API void SetLogTypeStringAfterLineToAll(std::string_view sALine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sALine =sALine;
    }

    LOGCRAFT_API void SetLogTypeStringAfterMessageToAll(std::string_view sAMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sAMessage = sAMessage;
    }
}