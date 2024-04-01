#pragma once

#include <string>
#include <optional>
#include <queue>
#include <initializer_list>

namespace lc
{
    enum class LogOrder
    {
        Time,
        Date,
        Function,
        Line,
        Level,
        Message
    };

    namespace internal
    {
        struct LogConfig
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
            bool m_bColorTime               = false;
            bool m_bColorDate               = false;
            bool m_bColorFunction           = false;
            bool m_bColorLine               = false;
            bool m_bColorMessage            = false;
            std::string m_sColorLevel       = "";
            std::string m_sColorTime        = "";
            std::string m_sColorDate        = "";
            std::string m_sColorFunction    = "";
            std::string m_sColorLine        = "";
            std::string m_sColorMessage     = "";

            std::queue<LogOrder> m_logOrder;
        };

        std::optional<const LogConfig&> GetLogConfig(std::string_view sLogType);
    }

    bool AddLogType(std::string_view sLogType);
    bool RemoveLogType(std::string_view sLogType);
    void SetLogTypeToFile(std::string_view sLogType, bool bLogToFile);
    void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole);
    void SetLogTypeTime(std::string_view sLogType, bool bLogTime);
    void SetLogTypeDate(std::string_view sLogType, bool bLogDate);
    void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction);
    void SetLogTypeLine(std::string_view sLogType, bool bLogLine);
    void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage);
    void SetLogTypeFilePath(std::string_view sLogType, std::string_view sLogFilePath);
    void SetLogTypeTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat);
    void SetLogTypeDateFormat(std::string_view sLogType, std::string_view sLogDateFormat);
    void SetLogTypeColorLevel(std::string_view sLogType, bool bColorLevel);
    void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime);
    void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate);
    void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction);
    void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine);
    void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage);
    void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColorLevel);
    void SetLogTypeColorTime(std::string_view sLogType, std::string_view sColorTime);
    void SetLogTypeColorDate(std::string_view sLogType, std::string_view sColorDate);
    void SetLogTypeColorFunction(std::string_view sLogType, std::string_view sColorFunction);
    void SetLogTypeColorLine(std::string_view sLogType, std::string_view sColorLine);
    void SetLogTypeColorMessage(std::string_view sLogType, std::string_view sColorMessage);
    void SetLogTypeOrder(std::string_view sLogType, std::queue<LogOrder> logOrder);
    void SetLogTypeOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);
}