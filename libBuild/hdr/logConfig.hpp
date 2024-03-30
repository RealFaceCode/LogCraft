#pragma once

#include <string>

namespace lc::internal
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
        
        LogConfig() = default;
        ~LogConfig() = default;
    };
}