#pragma once

#include <string>
#include <optional>
#include <vector>
#include <initializer_list>
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
        Message
    };

    namespace internal
    {
        struct LOGCRAFT_API LogConfig
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
            std::string m_sColorLevel       = "";
            std::string m_sColorLabel       = "";
            std::string m_sColorTime        = "";
            std::string m_sColorDate        = "";
            std::string m_sColorFunction    = "";
            std::string m_sColorLine        = "";
            std::string m_sColorMessage     = "";

            std::string m_sBLevel           = "";
            std::string m_sBLabel           = "";
            std::string m_sBTime            = "";
            std::string m_sBDate            = "";
            std::string m_sBFunction        = "";
            std::string m_sBLine            = "";
            std::string m_sBMessage         = "";

            std::string m_sALevel           = "";
            std::string m_sALabel           = "";
            std::string m_sATime            = "";
            std::string m_sADate            = "";
            std::string m_sAFunction        = "";
            std::string m_sALine            = "";
            std::string m_sAMessage         = "";

            std::vector<LogOrder> m_logOrder;
        };

        LOGCRAFT_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType);
    }

    //TODO: rename function
    LOGCRAFT_API bool AddLogType(std::string_view sLogType);
    LOGCRAFT_API bool RemoveLogType(std::string_view sLogType);

    LOGCRAFT_API void SetLogTypeToFile(std::string_view sLogType, bool bLogToFile);
    LOGCRAFT_API void SetLogTypeToFileToAll(bool bLogToFile);

    LOGCRAFT_API void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole);
    LOGCRAFT_API void SetLogTypeToConsoleToAll(bool bLogToConsole);

    LOGCRAFT_API void SetLogTypeTime(std::string_view sLogType, bool bLogTime);
    LOGCRAFT_API void SetLogTypeTimeToAll(bool bLogTime);

    LOGCRAFT_API void SetLogTypeDate(std::string_view sLogType, bool bLogDate);
    LOGCRAFT_API void SetLogTypeDateToAll(bool bLogDate);

    LOGCRAFT_API void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction);
    LOGCRAFT_API void SetLogTypeFunctionToAll(bool bLogFunction);

    LOGCRAFT_API void SetLogTypeLine(std::string_view sLogType, bool bLogLine);
    LOGCRAFT_API void SetLogTypeLineToAll(bool bLogLine);

    LOGCRAFT_API void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage);
    LOGCRAFT_API void SetLogTypeMessageToAll(bool bLogMessage);

    LOGCRAFT_API void SetLogTypeFilePath(std::string_view sLogType, std::string_view sLogFilePath);
    LOGCRAFT_API void SetLogTypeTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat);
    LOGCRAFT_API void SetLogTypeDateFormat(std::string_view sLogType, std::string_view sLogDateFormat);

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, bool bColorLevel);
    LOGCRAFT_API void SetLogTypeColorLevelToAll(bool bColorLevel);

    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, bool bColorLabel);
    LOGCRAFT_API void SetLogTypeColorLabelToAll(bool bColorLabel);

    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime);
    LOGCRAFT_API void SetLogTypeColorTimeToAll(bool bColorTime);

    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate);
    LOGCRAFT_API void SetLogTypeColorDateToAll(bool bColorDate);

    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction);
    LOGCRAFT_API void SetLogTypeColorFunctionToAll(bool bColorFunction);

    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine);
    LOGCRAFT_API void SetLogTypeColorLineToAll(bool bColorLine);

    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage);
    LOGCRAFT_API void SetLogTypeColorMessageToAll(bool bColorMessage);

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, std::string_view sColor);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, std::string_view sColor);

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, LogColor color);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, LogColor color);

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects);

    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::vector<LogOrder> logOrder);
    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);
    LOGCRAFT_API void SetLogTypeOrderToAll(std::vector<LogOrder> logOrder);
    LOGCRAFT_API void SetLogTypeOrderToAll(std::initializer_list<LogOrder> logOrder);

    LOGCRAFT_API void SetLogTypeStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel);
    LOGCRAFT_API void SetLogTypeStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel);
    LOGCRAFT_API void SetLogTypeStringBeforeTime(std::string_view sLogType, std::string_view sBTime);
    LOGCRAFT_API void SetLogTypeStringBeforeDate(std::string_view sLogType, std::string_view sBDate);
    LOGCRAFT_API void SetLogTypeStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction);
    LOGCRAFT_API void SetLogTypeStringBeforeLine(std::string_view sLogType, std::string_view sBLine);
    LOGCRAFT_API void SetLogTypeStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage);

    LOGCRAFT_API void SetLogTypeStringAfterLevel(std::string_view sLogType, std::string_view sALevel);
    LOGCRAFT_API void SetLogTypeStringAfterLabel(std::string_view sLogType, std::string_view sALabel);
    LOGCRAFT_API void SetLogTypeStringAfterTime(std::string_view sLogType, std::string_view sATime);
    LOGCRAFT_API void SetLogTypeStringAfterDate(std::string_view sLogType, std::string_view sADate);
    LOGCRAFT_API void SetLogTypeStringAfterFunction(std::string_view sLogType, std::string_view sAFunction);
    LOGCRAFT_API void SetLogTypeStringAfterLine(std::string_view sLogType, std::string_view sALine);
    LOGCRAFT_API void SetLogTypeStringAfterMessage(std::string_view sLogType, std::string_view sAMessage);

    LOGCRAFT_API void SetLogTypeStringBeforeLevelToAll(std::string_view sBLevel);
    LOGCRAFT_API void SetLogTypeStringBeforeLabelToAll(std::string_view sBLabel);
    LOGCRAFT_API void SetLogTypeStringBeforeTimeToAll(std::string_view sBTime);
    LOGCRAFT_API void SetLogTypeStringBeforeDateToAll(std::string_view sBDate);
    LOGCRAFT_API void SetLogTypeStringBeforeFunctionToAll(std::string_view sBFunction);
    LOGCRAFT_API void SetLogTypeStringBeforeLineToAll(std::string_view sBLine);
    LOGCRAFT_API void SetLogTypeStringBeforeMessageToAll(std::string_view sBMessage);


    LOGCRAFT_API void SetLogTypeStringAfterLevelToAll(std::string_view sALevel);
    LOGCRAFT_API void SetLogTypeStringAfterLabelToAll(std::string_view sALabel);
    LOGCRAFT_API void SetLogTypeStringAfterTimeToAll(std::string_view sATime);
    LOGCRAFT_API void SetLogTypeStringAfterDateToAll(std::string_view sADate);
    LOGCRAFT_API void SetLogTypeStringAfterFunctionToAll(std::string_view sAFunction);
    LOGCRAFT_API void SetLogTypeStringAfterLineToAll(std::string_view sALine);
    LOGCRAFT_API void SetLogTypeStringAfterMessageToAll(std::string_view sAMessage);
}