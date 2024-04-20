#pragma once

#include <string>
#include <optional>
#include <vector>
#include <initializer_list>
#include <set>

#include "defines.hpp"
#include "logColor.hpp"

namespace lc
{
    enum class LogOrder
    {
        Time,
        Date,
        Function,
        Line,
        Level,
        Label,
        Message,
        File,
        Trace,
    };

    namespace internal
    {
        struct LC_API LogConfig
        {
        public:
            bool m_bLogToFile               = false;
            bool m_bLogToConsole            = true;
            bool m_bLogTime                 = true;
            bool m_bLogDate                 = true;
            bool m_bLogFunction             = true;
            bool m_bLogLine                 = true;
            bool m_bLogLevel                = true;
            bool m_bLogMessage              = true;
            bool m_bLogFile                 = true;
            bool m_bLogTrace                = true;
            std::string m_sLogFilePath      = "log.txt";
            std::string m_sLogTimeFormat    = "%H:%M:%S";
            std::string m_sLogDateFormat    = "%d-%m-%Y";

            bool m_bColorLevel              = true;
            bool m_bColorLabel              = false;
            bool m_bColorTime               = false;
            bool m_bColorDate               = false;
            bool m_bColorFunction           = false;
            bool m_bColorLine               = false;
            bool m_bColorMessage            = false;
            bool m_bColorFile               = false;
            bool m_bColorTrace              = false;

            std::string m_sColorLevel       = "";
            std::string m_sColorLabel       = "";
            std::string m_sColorTime        = "";
            std::string m_sColorDate        = "";
            std::string m_sColorFunction    = "";
            std::string m_sColorLine        = "";
            std::string m_sColorMessage     = "";
            std::string m_sColorFile        = "";
            std::string m_sColorTrace       = "";

            std::string m_sBLevel           = "";
            std::string m_sBLabel           = "";
            std::string m_sBTime            = "";
            std::string m_sBDate            = "";
            std::string m_sBFunction        = "";
            std::string m_sBLine            = "";
            std::string m_sBMessage         = "";
            std::string m_sBFile            = "";
            std::string m_sBTrace           = "";

            std::string m_sALevel           = "";
            std::string m_sALabel           = "";
            std::string m_sATime            = "";
            std::string m_sADate            = "";
            std::string m_sAFunction        = "";
            std::string m_sALine            = "";
            std::string m_sAMessage         = "";
            std::string m_sAFile            = "";
            std::string m_sATrace           = "";

            std::string m_sBTraceFunction   = "";
            std::string m_sBTraceLine       = "";
            std::string m_sBTraceFile       = "";

            std::string m_sATraceFunction   = "";
            std::string m_sATraceLine       = "";
            std::string m_sATraceFile       = "";
            
            std::string m_sFormatTrim       = "";
            std::vector<LogOrder> m_logOrder;
            std::vector<LogOrder> m_logOrderTrace;
        };

        LC_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType);
        LC_API std::set<std::string>& GetAvailableOrders();
        LC_API std::set<std::string>& GetAvailableOrdersTrace();

        LC_API void SetLogStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel);
        LC_API void SetLogStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel);
        LC_API void SetLogStringBeforeTime(std::string_view sLogType, std::string_view sBTime);
        LC_API void SetLogStringBeforeDate(std::string_view sLogType, std::string_view sBDate);
        LC_API void SetLogStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction);
        LC_API void SetLogStringBeforeLine(std::string_view sLogType, std::string_view sBLine);
        LC_API void SetLogStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage);
        LC_API void SetLogStringBeforeFile(std::string_view sLogType, std::string_view sBFile);
        LC_API void SetLogStringBeforeTrace(std::string_view sLogType, std::string_view sBTrace);

        LC_API void SetLogStringAfterLevel(std::string_view sLogType, std::string_view sALevel);
        LC_API void SetLogStringAfterLabel(std::string_view sLogType, std::string_view sALabel);
        LC_API void SetLogStringAfterTime(std::string_view sLogType, std::string_view sATime);
        LC_API void SetLogStringAfterDate(std::string_view sLogType, std::string_view sADate);
        LC_API void SetLogStringAfterFunction(std::string_view sLogType, std::string_view sAFunction);
        LC_API void SetLogStringAfterLine(std::string_view sLogType, std::string_view sALine);
        LC_API void SetLogStringAfterMessage(std::string_view sLogType, std::string_view sAMessage);
        LC_API void SetLogStringAfterFile(std::string_view sLogType, std::string_view sAFile);
        LC_API void SetLogStringAfterTrace(std::string_view sLogType, std::string_view sATrace);

        LC_API void SetLogStringBeforeLevelToAll(std::string_view sBLevel);
        LC_API void SetLogStringBeforeLabelToAll(std::string_view sBLabel);
        LC_API void SetLogStringBeforeTimeToAll(std::string_view sBTime);
        LC_API void SetLogStringBeforeDateToAll(std::string_view sBDate);
        LC_API void SetLogStringBeforeFunctionToAll(std::string_view sBFunction);
        LC_API void SetLogStringBeforeLineToAll(std::string_view sBLine);
        LC_API void SetLogStringBeforeMessageToAll(std::string_view sBMessage);
        LC_API void SetLogStringBeforeFileToAll(std::string_view sBFile);
        LC_API void SetLogStringBeforeTraceToAll(std::string_view sBTrace);

        LC_API void SetLogStringAfterLevelToAll(std::string_view sALevel);
        LC_API void SetLogStringAfterLabelToAll(std::string_view sALabel);
        LC_API void SetLogStringAfterTimeToAll(std::string_view sATime);
        LC_API void SetLogStringAfterDateToAll(std::string_view sADate);
        LC_API void SetLogStringAfterFunctionToAll(std::string_view sAFunction);
        LC_API void SetLogStringAfterLineToAll(std::string_view sALine);
        LC_API void SetLogStringAfterMessageToAll(std::string_view sAMessage);
        LC_API void SetLogStringAfterFileToAll(std::string_view sAFile);
        LC_API void SetLogStringAfterTraceToAll(std::string_view sATrace);

        LC_API void SetLogStringBeforeTraceFunction(std::string_view sLogType, std::string_view sBTraceFunction);
        LC_API void SetLogStringBeforeTraceLine(std::string_view sLogType, std::string_view sBTraceLine);
        LC_API void SetLogStringBeforeTraceFile(std::string_view sLogType, std::string_view sBTraceFile);

        LC_API void SetLogStringAfterTraceFunction(std::string_view sLogType, std::string_view sATraceFunction);
        LC_API void SetLogStringAfterTraceLine(std::string_view sLogType, std::string_view sATraceLine);
        LC_API void SetLogStringAfterTraceFile(std::string_view sLogType, std::string_view sATraceFile);

        LC_API void SetLogStringBeforeTraceFunctionToAll(std::string_view sBTraceFunction);
        LC_API void SetLogStringBeforeTraceLineToAll(std::string_view sBTraceLine);
        LC_API void SetLogStringBeforeTraceFileToAll(std::string_view sBTraceFile);

        LC_API void SetLogStringAfterTraceFunctionToAll(std::string_view sATraceFunction);
        LC_API void SetLogStringAfterTraceLineToAll(std::string_view sATraceLine);
        LC_API void SetLogStringAfterTraceFileToAll(std::string_view sATraceFile);
    }

    LC_API bool AddLogType(std::string_view sLogType);
    LC_API bool RemoveLogType(std::string_view sLogType);

    LC_API void SetWriteToFile(std::string_view sLogType, bool bLogToFile);
    LC_API void SetWriteToFileToAll(bool bLogToFile);

    LC_API void SetWriteToConsole(std::string_view sLogType, bool bLogToConsole);
    LC_API void SetWriteToConsoleToAll(bool bLogToConsole);

    LC_API void SetLogTime(std::string_view sLogType, bool bLogTime);
    LC_API void SetLogTimeToAll(bool bLogTime);

    LC_API void SetLogDate(std::string_view sLogType, bool bLogDate);
    LC_API void SetLogDateToAll(bool bLogDate);

    LC_API void SetLogFunction(std::string_view sLogType, bool bLogFunction);
    LC_API void SetLogFunctionToAll(bool bLogFunction);

    LC_API void SetLogLine(std::string_view sLogType, bool bLogLine);
    LC_API void SetLogLineToAll(bool bLogLine);

    LC_API void SetLogMessage(std::string_view sLogType, bool bLogMessage);
    LC_API void SetLogMessageToAll(bool bLogMessage);

    LC_API void SetLogFile(std::string_view sLogType, bool bLogFile);
    LC_API void SetLogFileToAll(bool bLogFile);

    LC_API void SetLogTrace(std::string_view sLogType, bool bLogTrace);
    LC_API void SetLogTraceToAll(bool bLogTrace);

    LC_API void SetLogFilePath(std::string_view sLogType, std::string_view sLogFilePath);
    LC_API void SetLogTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat);
    LC_API void SetLogDateFormat(std::string_view sLogType, std::string_view sLogDateFormat);

    LC_API void SetLogColorLevel(std::string_view sLogType, bool bColorLevel);
    LC_API void SetLogColorLevelToAll(bool bColorLevel);

    LC_API void SetLogColorLabel(std::string_view sLogType, bool bColorLabel);
    LC_API void SetLogColorLabelToAll(bool bColorLabel);

    LC_API void SetLogColorTime(std::string_view sLogType, bool bColorTime);
    LC_API void SetLogColorTimeToAll(bool bColorTime);

    LC_API void SetLogColorDate(std::string_view sLogType, bool bColorDate);
    LC_API void SetLogColorDateToAll(bool bColorDate);

    LC_API void SetLogColorFunction(std::string_view sLogType, bool bColorFunction);
    LC_API void SetLogColorFunctionToAll(bool bColorFunction);

    LC_API void SetLogColorLine(std::string_view sLogType, bool bColorLine);
    LC_API void SetLogColorLineToAll(bool bColorLine);

    LC_API void SetLogColorMessage(std::string_view sLogType, bool bColorMessage);
    LC_API void SetLogColorMessageToAll(bool bColorMessage);

    LC_API void SetLogColorFile(std::string_view sLogType, bool bColorFile);
    LC_API void SetLogColorFileToAll(bool bColorFile);

    LC_API void SetLogColorTrace(std::string_view sLogType, bool bColorTrace);
    LC_API void SetLogColorTraceToAll(bool bColorTrace);

    LC_API void SetLogColorLevel(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorLabel(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorTime(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorDate(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorFunction(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorLine(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorMessage(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorFile(std::string_view sLogType, std::string_view sColor);
    LC_API void SetLogColorTrace(std::string_view sLogType, std::string_view sColor);

    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color);
    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color);

    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    LC_API void SetLogColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorFile(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LC_API void SetLogColorTrace(std::string_view sLogType, const std::vector<LogEffect>& effects);

    LC_API void SetLogOrder(std::string_view sLogType, std::vector<LogOrder> logOrder);
    LC_API void SetLogOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);
    LC_API void SetLogOrderToAll(std::vector<LogOrder> logOrder);
    LC_API void SetLogOrderToAll(std::initializer_list<LogOrder> logOrder);

    LC_API void SetLogOrderTrace(std::string_view sLogType, std::vector<LogOrder> logOrder);
    LC_API void SetLogOrderTrace(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);
    LC_API void SetLogOrderTraceToAll(std::vector<LogOrder> logOrder);
    LC_API void SetLogOrderTraceToAll(std::initializer_list<LogOrder> logOrder);

    LC_API void SetFormatTrim(std::string_view sLogType, std::string_view sFormatTrim);
    LC_API void SetFormatTrimToAll(std::string_view sFormatTrim);

    LC_API void SetFormat(std::string_view sLogType, std::string_view sFormat);
    LC_API void SetFormatToAll(std::string_view sFormat);

    LC_API void SetFormatTrace(std::string_view sLogType, std::string_view sFormat);
    LC_API void SetFormatTraceToAll(std::string_view sFormat);
}