#pragma once

#include <string>
#include <optional>
#include <vector>
#include <initializer_list>
#include "defines.hpp"

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

            std::vector<LogOrder> m_logOrder;
        };

        LOGCRAFT_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType);
    }

    LOGCRAFT_API bool AddLogType(std::string_view sLogType);
    LOGCRAFT_API bool RemoveLogType(std::string_view sLogType);
    LOGCRAFT_API void SetLogTypeToFile(std::string_view sLogType, bool bLogToFile);
    LOGCRAFT_API void SetLogTypeToConsole(std::string_view sLogType, bool bLogToConsole);
    LOGCRAFT_API void SetLogTypeTime(std::string_view sLogType, bool bLogTime);
    LOGCRAFT_API void SetLogTypeDate(std::string_view sLogType, bool bLogDate);
    LOGCRAFT_API void SetLogTypeFunction(std::string_view sLogType, bool bLogFunction);
    LOGCRAFT_API void SetLogTypeLine(std::string_view sLogType, bool bLogLine);
    LOGCRAFT_API void SetLogTypeMessage(std::string_view sLogType, bool bLogMessage);
    LOGCRAFT_API void SetLogTypeFilePath(std::string_view sLogType, std::string_view sLogFilePath);
    LOGCRAFT_API void SetLogTypeTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat);
    LOGCRAFT_API void SetLogTypeDateFormat(std::string_view sLogType, std::string_view sLogDateFormat);
    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, bool bColorLevel);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, bool bColorTime);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, bool bColorDate);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, bool bColorFunction);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, bool bColorLine);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, bool bColorMessage);
    LOGCRAFT_API void SetLogTypeColorLevel(std::string_view sLogType, std::string_view sColorLevel);
    LOGCRAFT_API void SetLogTypeColorTime(std::string_view sLogType, std::string_view sColorTime);
    LOGCRAFT_API void SetLogTypeColorDate(std::string_view sLogType, std::string_view sColorDate);
    LOGCRAFT_API void SetLogTypeColorFunction(std::string_view sLogType, std::string_view sColorFunction);
    LOGCRAFT_API void SetLogTypeColorLine(std::string_view sLogType, std::string_view sColorLine);
    LOGCRAFT_API void SetLogTypeColorMessage(std::string_view sLogType, std::string_view sColorMessage);
    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::vector<LogOrder> logOrder);
    LOGCRAFT_API void SetLogTypeOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);
}