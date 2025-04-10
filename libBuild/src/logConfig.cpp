#include "logcraft/logConfig.hpp"

#include <unordered_map>
#include <ranges>
#include <algorithm>

#include "logcraft/logcraftConfig.hpp"
namespace lc
{
    std::unordered_map<std::string, internal::LogConfig> g_logConfigMap;
    std::set<std::string> g_availableOrderTypes = {"{LEVEL}", "{LABEL}", "{TIME}", "{DATE}", "{FUNC}", "{LINE}", "{MSG}", "{FILE}", "{TRACE}"};
    std::set<std::string> g_availableOrderTypesTrace = {"{FUNC}", "{LINE}", "{FILE}"};
    
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

        LC_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                return it->second;
            return std::nullopt;
        }

        LC_API std::set<std::string>& GetAvailableOrders()
        {
            return g_availableOrderTypes;
        }

        LC_API std::set<std::string>& GetAvailableOrdersTrace()
        {
            return g_availableOrderTypesTrace;
        }

        LC_API void SetLogStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBLevel = sBLevel;
        }

        LC_API void SetLogStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBLabel = sBLabel;
        }

        LC_API void SetLogStringBeforeTime(std::string_view sLogType, std::string_view sBTime)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTime = sBTime;
        }   

        LC_API void SetLogStringBeforeDate(std::string_view sLogType, std::string_view sBDate)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBDate = sBDate;
        }

        LC_API void SetLogStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBFunction = sBFunction;
        }

        LC_API void SetLogStringBeforeLine(std::string_view sLogType, std::string_view sBLine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBLine = sBLine;
        }

        LC_API void SetLogStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBMessage = sBMessage;
        }

        LC_API void SetLogStringBeforeFile(std::string_view sLogType, std::string_view sBFile)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBFile = sBFile;
        }

        LC_API void SetLogStringBeforeTrace(std::string_view sLogType, std::string_view sBTrace)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTrace = sBTrace;
        }

        LC_API void SetLogStringAfterLevel(std::string_view sLogType, std::string_view sALevel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALevel = sALevel;
        }

        LC_API void SetLogStringAfterLabel(std::string_view sLogType, std::string_view sALabel)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALabel = sALabel;
        }

        LC_API void SetLogStringAfterTime(std::string_view sLogType, std::string_view sATime)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATime = sATime;
        }

        LC_API void SetLogStringAfterDate(std::string_view sLogType, std::string_view sADate)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sADate = sADate;
        }

        LC_API void SetLogStringAfterFunction(std::string_view sLogType, std::string_view sAFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sAFunction = sAFunction;
        }

        LC_API void SetLogStringAfterLine(std::string_view sLogType, std::string_view sALine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sALine = sALine;
        }

        LC_API void SetLogStringAfterMessage(std::string_view sLogType, std::string_view sAMessage)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sAMessage = sAMessage;
        }

        LC_API void SetLogStringAfterFile(std::string_view sLogType, std::string_view sAFile)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sAFile = sAFile;
        }

        LC_API void SetLogStringAfterTrace(std::string_view sLogType, std::string_view sATrace)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATrace = sATrace;
        }

        LC_API void SetLogStringBeforeLevelToAll(std::string_view sBLevel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLevel = sBLevel;
        }

        LC_API void SetLogStringBeforeLabelToAll(std::string_view sBLabel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLabel = sBLabel;
        }

        LC_API void SetLogStringBeforeTimeToAll(std::string_view sBTime)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTime = sBTime;
        }

        LC_API void SetLogStringBeforeDateToAll(std::string_view sBDate)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBDate = sBDate;
        }

        LC_API void SetLogStringBeforeFunctionToAll(std::string_view sBFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBFunction = sBFunction;
        }

        LC_API void SetLogStringBeforeLineToAll(std::string_view sBLine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBLine = sBLine;
        }

        LC_API void SetLogStringBeforeMessageToAll(std::string_view sBMessage)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBMessage = sBMessage;
        }

        LC_API void SetLogStringBeforeFileToAll(std::string_view sBFile)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBFile = sBFile;
        }

        LC_API void SetLogStringBeforeTraceToAll(std::string_view sBTrace)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTrace = sBTrace;
        }

        LC_API void SetLogStringAfterLevelToAll(std::string_view sALevel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALevel = sALevel;
        }

        LC_API void SetLogStringAfterLabelToAll(std::string_view sALabel)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALabel = sALabel;
        }

        LC_API void SetLogStringAfterTimeToAll(std::string_view sATime)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATime = sATime;
        }

        LC_API void SetLogStringAfterDateToAll(std::string_view sADate)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sADate = sADate;
        }

        LC_API void SetLogStringAfterFunctionToAll(std::string_view sAFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sAFunction = sAFunction;
        }

        LC_API void SetLogStringAfterLineToAll(std::string_view sALine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sALine =sALine;
        }

        LC_API void SetLogStringAfterMessageToAll(std::string_view sAMessage)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sAMessage = sAMessage;
        }

        LC_API void SetLogStringAfterFileToAll(std::string_view sAFile)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sAFile = sAFile;
        }

        LC_API void SetLogStringAfterTraceToAll(std::string_view sATrace)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATrace = sATrace;
        }

        LC_API void SetLogStringBeforeTraceFunction(std::string_view sLogType, std::string_view sBTraceFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTraceFunction = sBTraceFunction;
        }

        LC_API void SetLogStringBeforeTraceLine(std::string_view sLogType, std::string_view sBTraceLine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTraceLine = sBTraceLine;
        }

        LC_API void SetLogStringBeforeTraceFile(std::string_view sLogType, std::string_view sBTraceFile)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sBTraceFile = sBTraceFile;
        }

        LC_API void SetLogStringAfterTraceFunction(std::string_view sLogType, std::string_view sATraceFunction)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATraceFunction = sATraceFunction;
        }

        LC_API void SetLogStringAfterTraceLine(std::string_view sLogType, std::string_view sATraceLine)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATraceLine = sATraceLine;
        }

        LC_API void SetLogStringAfterTraceFile(std::string_view sLogType, std::string_view sATraceFile)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sATraceFile = sATraceFile;
        }

        LC_API void SetLogStringBeforeTraceFunctionToAll(std::string_view sBTraceFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTraceFunction = sBTraceFunction;
        }

        LC_API void SetLogStringBeforeTraceLineToAll(std::string_view sBTraceLine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTraceLine = sBTraceLine;
        }

        LC_API void SetLogStringBeforeTraceFileToAll(std::string_view sBTraceFile)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sBTraceFile = sBTraceFile;
        }

        LC_API void SetLogStringAfterTraceFunctionToAll(std::string_view sATraceFunction)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATraceFunction = sATraceFunction;
        }

        LC_API void SetLogStringAfterTraceLineToAll(std::string_view sATraceLine)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATraceLine = sATraceLine;
        }

        LC_API void SetLogStringAfterTraceFileToAll(std::string_view sATraceFile)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sATraceFile = sATraceFile;
        }

        LC_API void SetLogStringLeftOver(std::string_view sLogType, std::string_view sLeftOver)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sLeftOver = sLeftOver;
        }

        LC_API void SetLogStringLeftOverToAll(std::string_view sLeftOver)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sLeftOver = sLeftOver;
        }

        LC_API void SetLogStringLeftOverTrace(std::string_view sLogType, std::string_view sLeftOverTrace)
        {
            auto it = g_logConfigMap.find(std::string(sLogType));
            if (it != g_logConfigMap.end())
                it->second.m_sLeftOverTrace = sLeftOverTrace;
        }

        LC_API void SetLogStringLeftOverTraceToAll(std::string_view sLeftOverTrace)
        {
            for (auto& [key, value] : g_logConfigMap)
                value.m_sLeftOverTrace = sLeftOverTrace;
        }
    }

    LC_API bool AddLogType(std::string_view sLogType)
    {
        auto [it, succes] = g_logConfigMap.try_emplace(std::string(sLogType), internal::LogConfig());

        auto& lcConfig = internal::GetLogCraftConfig();

        if (lcConfig.m_nCurrentMaxLevelWidth < sLogType.size())
            lcConfig.m_nCurrentMaxLevelWidth = sLogType.size();

        return succes;
    }

    LC_API bool RemoveLogType(std::string_view sLogType)
    {
        return g_logConfigMap.erase(std::string(sLogType));
    }

    LC_API void SetWriteToFile(std::string_view sLogType, bool bLogToFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToFile = bLogToFile;
    }

    LC_API void SetWriteToFileToAll(bool bLogToFile)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToFile = bLogToFile;
    }

    LC_API void SetWriteToConsole(std::string_view sLogType, bool bLogToConsole)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogToConsole = bLogToConsole;
    }

    LC_API void SetWriteToConsoleToAll(bool bLogToConsole)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogToConsole = bLogToConsole;
    }

    LC_API void SetLogTime(std::string_view sLogType, bool bLogTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTime = bLogTime;
    }

    LC_API void SetLogTimeToAll(bool bLogTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogTime = bLogTime;
    }

    LC_API void SetLogDate(std::string_view sLogType, bool bLogDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogDate = bLogDate;
    }

    LC_API void SetLogDateToAll(bool bLogDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogDate = bLogDate;
    }

    LC_API void SetLogFunction(std::string_view sLogType, bool bLogFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFunction = bLogFunction;
    }

    LC_API void SetLogFunctionToAll(bool bLogFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogFunction = bLogFunction;
    }

    LC_API void SetLogLine(std::string_view sLogType, bool bLogLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLine = bLogLine;
    }

    LC_API void SetLogLineToAll(bool bLogLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLine = bLogLine;
    }

    LC_API void SetLogLevel(std::string_view sLogType, bool bLogLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogLevel = bLogLevel;
    }

    LC_API void SetLogLevelToAll(bool bLogLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogLevel = bLogLevel;
    }

    LC_API void SetLogMessage(std::string_view sLogType, bool bLogMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogMessage = bLogMessage;
    }

    LC_API void SetLogMessageToAll(bool bLogMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogMessage = bLogMessage;
    }

    LC_API void SetLogFile(std::string_view sLogType, bool bLogFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogFile = bLogFile;
    }

    LC_API void SetLogFileToAll(bool bLogFile)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogFile = bLogFile;
    }

    LC_API void SetLogTrace(std::string_view sLogType, bool bLogTrace)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bLogTrace = bLogTrace;
    }

    LC_API void SetLogTraceToAll(bool bLogTrace)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bLogTrace = bLogTrace;
    }

    LC_API void SetLogFilePath(std::string_view sLogType, std::string_view sLogFilePath)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogFilePath = std::string(sLogFilePath);
    }

    LC_API void SetLogTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogTimeFormat = std::string(sLogTimeFormat);
    }

    LC_API void SetLogDateFormat(std::string_view sLogType, std::string_view sLogDateFormat)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sLogDateFormat = std::string(sLogDateFormat);
    }

    LC_API void SetLogColorLevel(std::string_view sLogType, bool bColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLevel = bColorLevel;
    }

    LC_API void SetLogColorLevelToAll(bool bColorLevel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLevel = bColorLevel;
    }

    LC_API void SetLogColorLabel(std::string_view sLogType, bool bColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLabel = bColorLabel;
    }

    LC_API void SetLogColorLabelToAll(bool bColorLabel)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLabel = bColorLabel;
    }

    LC_API void SetLogColorTime(std::string_view sLogType, bool bColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTime = bColorTime;
    }

    LC_API void SetLogColorTimeToAll(bool bColorTime)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorTime = bColorTime;
    }

    LC_API void SetLogColorDate(std::string_view sLogType, bool bColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorDate = bColorDate;
    }

    LC_API void SetLogColorDateToAll(bool bColorDate)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorDate = bColorDate;
    }

    LC_API void SetLogColorFunction(std::string_view sLogType, bool bColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFunction = bColorFunction;
    }

    LC_API void SetLogColorFunctionToAll(bool bColorFunction)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorFunction = bColorFunction;
    }

    LC_API void SetLogColorLine(std::string_view sLogType, bool bColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorLine = bColorLine;
    }

    LC_API void SetLogColorLineToAll(bool bColorLine)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorLine = bColorLine;
    }

    LC_API void SetLogColorMessage(std::string_view sLogType, bool bColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorMessage = bColorMessage;
    }

    LC_API void SetLogColorMessageToAll(bool bColorMessage)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorMessage = bColorMessage;
    }

    LC_API void SetLogColorFile(std::string_view sLogType, bool bColorFile)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorFile = bColorFile;
    }

    LC_API void SetLogColorFileToAll(bool bColorFile)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorFile = bColorFile;
    }

    LC_API void SetLogColorTrace(std::string_view sLogType, bool bColorTrace)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_bColorTrace = bColorTrace;
    }

    LC_API void SetLogColorTraceToAll(bool bColorTrace)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_bColorTrace = bColorTrace;
    }

    LC_API void SetLogColorLevel(std::string_view sLogType, std::string_view sColorLevel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = std::string(sColorLevel);
    }

    LC_API void SetLogColorLabel(std::string_view sLogType, std::string_view sColorLabel)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = std::string(sColorLabel);
    }

    LC_API void SetLogColorTime(std::string_view sLogType, std::string_view sColorTime)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = std::string(sColorTime);
    }

    LC_API void SetLogColorDate(std::string_view sLogType, std::string_view sColorDate)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = std::string(sColorDate);
    }

    LC_API void SetLogColorFunction(std::string_view sLogType, std::string_view sColorFunction)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = std::string(sColorFunction);
    }

    LC_API void SetLogColorLine(std::string_view sLogType, std::string_view sColorLine)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = std::string(sColorLine);
    }

    LC_API void SetLogColorMessage(std::string_view sLogType, std::string_view sColorMessage)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = std::string(sColorMessage);
    }

    LC_API void SetLogColorFile(std::string_view sLogType, std::string_view sColor)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFile = std::string(sColor);
    }

    LC_API void SetLogColorTrace(std::string_view sLogType, std::string_view sColor)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTrace = std::string(sColor);
    }

    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetColor(color);
    }

    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetColor(color);
    }

    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetColor(color);
    }

    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetColor(color);
    }

    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetColor(color);
    }

    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetColor(color);
    }

    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetColor(color);
    }

    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFile = internal::GetColor(color);
    }

    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTrace = internal::GetColor(color);
    }

    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFile = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTrace = internal::CreateAsciiEscapeSequence(color, effects);
    }

    LC_API void SetLogColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLevel = internal::GetEffects(effects);
    }

    LC_API void SetLogColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLabel = internal::GetEffects(effects);
    }

    LC_API void SetLogColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTime = internal::GetEffects(effects);
    }

    LC_API void SetLogColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorDate = internal::GetEffects(effects);
    }

    LC_API void SetLogColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFunction = internal::GetEffects(effects);
    }

    LC_API void SetLogColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorLine = internal::GetEffects(effects);
    }

    LC_API void SetLogColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorMessage = internal::GetEffects(effects);
    }

    LC_API void SetLogColorFile(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorFile = internal::GetEffects(effects);
    }

    LC_API void SetLogColorTrace(std::string_view sLogType, const std::vector<LogEffect>& effects)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sColorTrace = internal::GetEffects(effects);
    }

    LC_API void SetLogOrder(std::string_view sLogType, std::vector<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_logOrder = logOrder;
    }

    LC_API void SetLogOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
        {
            it->second.m_logOrder.clear();
            it->second.m_logOrder.insert(it->second.m_logOrder.end(), logOrder.begin(), logOrder.end());
        }
    }

    LC_API void SetLogOrderToAll(std::vector<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_logOrder = logOrder;
    }

    LC_API void SetLogOrderToAll(std::initializer_list<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
        {
            value.m_logOrder.clear();
            value.m_logOrder.insert(value.m_logOrder.end(), logOrder.begin(), logOrder.end());
        }
    }

    LC_API void SetLogOrderTrace(std::string_view sLogType, std::vector<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_logOrderTrace = logOrder;
    }

    LC_API void SetLogOrderTrace(std::string_view sLogType, std::initializer_list<LogOrder> logOrder)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
        {
            it->second.m_logOrderTrace.clear();
            it->second.m_logOrderTrace.insert(it->second.m_logOrderTrace.end(), logOrder.begin(), logOrder.end());
        }
    }

    LC_API void SetLogOrderTraceToAll(std::vector<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_logOrderTrace = logOrder;
    }

    LC_API void SetLogOrderTraceToAll(std::initializer_list<LogOrder> logOrder)
    {
        for (auto& [key, value] : g_logConfigMap)
        {
            value.m_logOrderTrace.clear();
            value.m_logOrderTrace.insert(value.m_logOrderTrace.end(), logOrder.begin(), logOrder.end());
        }
    }

    LC_API void SetFormatTrim(std::string_view sLogType, std::string_view sFormatTrim)
    {
        auto it = g_logConfigMap.find(std::string(sLogType));
        if (it != g_logConfigMap.end())
            it->second.m_sFormatTrim = sFormatTrim;
    }

    LC_API void SetFormatTrimToAll(std::string_view sFormatTrim)
    {
        for (auto& [key, value] : g_logConfigMap)
            value.m_sFormatTrim = sFormatTrim;
    }

    void FillOrder(const std::vector<std::pair<std::size_t, std::string>>& indexPos, std::string_view sLogType, std::string& format, std::string_view trim, std::vector<LogOrder>& logOrder)
    {
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
            else if(pair.second == "{FILE}")
            {
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeFile(sLogType, infront);
                internal::SetLogStringAfterFile(sLogType, after);
                logOrder.emplace_back(LogOrder::File);
            }
            else if(pair.second == "{TRACE}")
            {
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeTrace(sLogType, infront);
                internal::SetLogStringAfterTrace(sLogType, after);
                logOrder.emplace_back(LogOrder::Trace);
            }
        }

        if(!format.empty())
        {
            internal::SetLogStringLeftOver(sLogType, format);
        }
    }

    LC_API void SetFormat(std::string_view sLogType, std::string_view sFormat)
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

        std::ranges::sort(indexPos);
        std::string format(sFormat);

        auto config = internal::GetLogConfig(sLogType);
        if(!config)
            return;

        auto trim = config->get().m_sFormatTrim;
        if(trim.empty())
            trim = "] ";

        std::vector<LogOrder> logOrder;
        FillOrder(indexPos, sLogType, format, trim, logOrder);
        SetLogOrder(sLogType, logOrder);
    }

    LC_API void SetFormatToAll(std::string_view sFormat)
    {
        for(auto& [key, value] : g_logConfigMap)
            SetFormat(key, sFormat);
    }

    void FillOrderTrace(const std::vector<std::pair<std::size_t, std::string>>& indexPos, std::string_view sLogType, std::string& format, std::string_view trim, std::vector<LogOrder>& logOrder)
    {
        for(auto pair : indexPos)
        {
            if(pair.second == "{FUNC}")
            {
                SetLogFunction(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeTraceFunction(sLogType, infront);
                internal::SetLogStringAfterTraceFunction(sLogType, after);
                logOrder.emplace_back(LogOrder::Function);
            }
            else if(pair.second == "{LINE}")
            {
                SetLogLine(sLogType, true);
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeTraceLine(sLogType, infront);
                internal::SetLogStringAfterTraceLine(sLogType, after);
                logOrder.emplace_back(LogOrder::Line);
            }
            else if(pair.second == "{FILE}")
            {
                auto [infront, after] = internal::GetInfrontAndAfterTrim(format, pair.second, trim);
                internal::SetLogStringBeforeTraceFile(sLogType, infront);
                internal::SetLogStringAfterTraceFile(sLogType, after);
                logOrder.emplace_back(LogOrder::File);
            }
        }

        if(!format.empty())
        {
            internal::SetLogStringLeftOverTrace(sLogType, format);
        }
    }

    LC_API void SetFormatTrace(std::string_view sLogType, std::string_view sFormatTrace)
    {
        std::vector<std::pair<std::size_t, std::string>> indexPos;
        for(auto key : g_availableOrderTypes)
        {
            std::size_t pos = sFormatTrace.find(key);
            if (pos != std::string::npos)
                indexPos.push_back({pos, key});
        }

        if(indexPos.empty())
            return;

        std::ranges::sort(indexPos);
        std::string format(sFormatTrace);

        auto config = internal::GetLogConfig(sLogType);
        if(!config)
            return;

        auto trim = config->get().m_sFormatTrim;
        if(trim.empty())
            trim = "] ";

        std::vector<LogOrder> logOrder;
        FillOrderTrace(indexPos, sLogType, format, trim, logOrder);
        SetLogOrderTrace(sLogType, logOrder);
    }

    LC_API void SetFormatTraceToAll(std::string_view sFormatTrace)
    {
        for (auto& [key, value] : g_logConfigMap)
            SetFormatTrace(key, sFormatTrace);
    }
}