#pragma once

#include <string>
#include <optional>

namespace lc
{
    namespace internal
    {
        struct LogConfig
        {
        public:
            bool m_bLogToFile           = false;
            bool m_bLogToConsole        = true;
            bool m_bLogTime             = true;
            bool m_bLogDate             = true;
            bool m_bLogFunction         = true;
            bool m_bLogLine             = true;
            bool m_bLogLevel            = true;
            bool m_bLogMessage          = true;
            std::string m_sLogFilePath  = "log.txt";
            std::string m_sLogTimeFormat = "%H:%M:%S";
            std::string m_sLogDateFormat = "%d-%m-%Y";
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

}