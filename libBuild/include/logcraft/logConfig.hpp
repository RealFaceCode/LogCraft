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
    /**
     * @brief Enum representing the order of log components.
     * 
     * @note Used to specify the sequence in which log components appear.
     */
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
        /**
         * @brief Struct for log configuration settings.
         * 
         * @note Contains various settings for logging behavior and formatting.
         */
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

            std::string m_sLeftOver         = "";
            std::string m_sLeftOverTrace    = "";
            
            std::string m_sFormatTrim       = "";
            std::vector<LogOrder> m_logOrder;
            std::vector<LogOrder> m_logOrderTrace;
        };

        /**
         * @brief Retrieves the log configuration for a given log type.
         * 
         * @param sLogType The type of log to retrieve the configuration for.
         * @return An optional reference to the LogConfig.
         */
        LC_API std::optional<std::reference_wrapper<LogConfig>> GetLogConfig(std::string_view sLogType);

        /**
         * @brief Gets the set of available log orders.
         * 
         * @return A reference to the set of available log orders.
         */
        LC_API std::set<std::string>& GetAvailableOrders();

        /**
         * @brief Gets the set of available trace log orders.
         * 
         * @return A reference to the set of available trace log orders.
         */
        LC_API std::set<std::string>& GetAvailableOrdersTrace();

        /**
         * @brief Sets the string to be logged before the log level.
         * 
         * @param sLogType The type of log.
         * @param sBLevel The string to be logged before the log level.
         */
        LC_API void SetLogStringBeforeLevel(std::string_view sLogType, std::string_view sBLevel);

        /**
         * @brief Sets the string to be logged before the log label.
         * 
         * @param sLogType The type of log.
         * @param sBLabel The string to be logged before the log label.
         */
        LC_API void SetLogStringBeforeLabel(std::string_view sLogType, std::string_view sBLabel);

        /**
         * @brief Sets the string to be logged before the log time.
         * 
         * @param sLogType The type of log.
         * @param sBTime The string to be logged before the log time.
         */
        LC_API void SetLogStringBeforeTime(std::string_view sLogType, std::string_view sBTime);

        /**
         * @brief Sets the string to be logged before the log date.
         * 
         * @param sLogType The type of log.
         * @param sBDate The string to be logged before the log date.
         */
        LC_API void SetLogStringBeforeDate(std::string_view sLogType, std::string_view sBDate);

        /**
         * @brief Sets the string to be logged before the log function.
         * 
         * @param sLogType The type of log.
         * @param sBFunction The string to be logged before the log function.
         */
        LC_API void SetLogStringBeforeFunction(std::string_view sLogType, std::string_view sBFunction);

        /**
         * @brief Sets the string to be logged before the log line.
         * 
         * @param sLogType The type of log.
         * @param sBLine The string to be logged before the log line.
         */
        LC_API void SetLogStringBeforeLine(std::string_view sLogType, std::string_view sBLine);

        /**
         * @brief Sets the string to be logged before the log message.
         * 
         * @param sLogType The type of log.
         * @param sBMessage The string to be logged before the log message.
         */
        LC_API void SetLogStringBeforeMessage(std::string_view sLogType, std::string_view sBMessage);

        /**
         * @brief Sets the string to be logged before the log file.
         * 
         * @param sLogType The type of log.
         * @param sBFile The string to be logged before the log file.
         */
        LC_API void SetLogStringBeforeFile(std::string_view sLogType, std::string_view sBFile);

        /**
         * @brief Sets the string to be logged before the log trace.
         * 
         * @param sLogType The type of log.
         * @param sBTrace The string to be logged before the log trace.
         */
        LC_API void SetLogStringBeforeTrace(std::string_view sLogType, std::string_view sBTrace);

        /**
         * @brief Sets the string to be logged after the log level.
         * 
         * @param sLogType The type of log.
         * @param sALevel The string to be logged after the log level.
         */
        LC_API void SetLogStringAfterLevel(std::string_view sLogType, std::string_view sALevel);

        /**
         * @brief Sets the string to be logged after the log label.
         * 
         * @param sLogType The type of log.
         * @param sALabel The string to be logged after the log label.
         */
        LC_API void SetLogStringAfterLabel(std::string_view sLogType, std::string_view sALabel);

        /**
         * @brief Sets the string to be logged after the log time.
         * 
         * @param sLogType The type of log.
         * @param sATime The string to be logged after the log time.
         */
        LC_API void SetLogStringAfterTime(std::string_view sLogType, std::string_view sATime);

        /**
         * @brief Sets the string to be logged after the log date.
         * 
         * @param sLogType The type of log.
         * @param sADate The string to be logged after the log date.
         */
        LC_API void SetLogStringAfterDate(std::string_view sLogType, std::string_view sADate);

        /**
         * @brief Sets the string to be logged after the log function.
         * 
         * @param sLogType The type of log.
         * @param sAFunction The string to be logged after the log function.
         */
        LC_API void SetLogStringAfterFunction(std::string_view sLogType, std::string_view sAFunction);

        /**
         * @brief Sets the string to be logged after the log line.
         * 
         * @param sLogType The type of log.
         * @param sALine The string to be logged after the log line.
         */
        LC_API void SetLogStringAfterLine(std::string_view sLogType, std::string_view sALine);

        /**
         * @brief Sets the string to be logged after the log message.
         * 
         * @param sLogType The type of log.
         * @param sAMessage The string to be logged after the log message.
         */
        LC_API void SetLogStringAfterMessage(std::string_view sLogType, std::string_view sAMessage);

        /**
         * @brief Sets the string to be logged after the log file.
         * 
         * @param sLogType The type of log.
         * @param sAFile The string to be logged after the log file.
         */
        LC_API void SetLogStringAfterFile(std::string_view sLogType, std::string_view sAFile);

        /**
         * @brief Sets the string to be logged after the log trace.
         * 
         * @param sLogType The type of log.
         * @param sATrace The string to be logged after the log trace.
         */
        LC_API void SetLogStringAfterTrace(std::string_view sLogType, std::string_view sATrace);

        /**
         * @brief Sets the string to be logged before the log level for all log types.
         * 
         * @param sBLevel The string to be logged before the log level.
         */
        LC_API void SetLogStringBeforeLevelToAll(std::string_view sBLevel);

        /**
         * @brief Sets the string to be logged before the log label for all log types.
         * 
         * @param sBLabel The string to be logged before the log label.
         */
        LC_API void SetLogStringBeforeLabelToAll(std::string_view sBLabel);

        /**
         * @brief Sets the string to be logged before the log time for all log types.
         * 
         * @param sBTime The string to be logged before the log time.
         */
        LC_API void SetLogStringBeforeTimeToAll(std::string_view sBTime);

        /**
         * @brief Sets the string to be logged before the log date for all log types.
         * 
         * @param sBDate The string to be logged before the log date.
         */
        LC_API void SetLogStringBeforeDateToAll(std::string_view sBDate);

        /**
         * @brief Sets the string to be logged before the log function for all log types.
         * 
         * @param sBFunction The string to be logged before the log function.
         */
        LC_API void SetLogStringBeforeFunctionToAll(std::string_view sBFunction);

        /**
         * @brief Sets the string to be logged before the log line for all log types.
         * 
         * @param sBLine The string to be logged before the log line.
         */
        LC_API void SetLogStringBeforeLineToAll(std::string_view sBLine);

        /**
         * @brief Sets the string to be logged before the log message for all log types.
         * 
         * @param sBMessage The string to be logged before the log message.
         */
        LC_API void SetLogStringBeforeMessageToAll(std::string_view sBMessage);

        /**
         * @brief Sets the string to be logged before the log file for all log types.
         * 
         * @param sBFile The string to be logged before the log file.
         */
        LC_API void SetLogStringBeforeFileToAll(std::string_view sBFile);

        /**
         * @brief Sets the string to be logged before the log trace for all log types.
         * 
         * @param sBTrace The string to be logged before the log trace.
         */
        LC_API void SetLogStringBeforeTraceToAll(std::string_view sBTrace);

        /**
         * @brief Sets the string to be logged after the log level for all log types.
         * 
         * @param sALevel The string to be logged after the log level.
         */
        LC_API void SetLogStringAfterLevelToAll(std::string_view sALevel);

        /**
         * @brief Sets the string to be logged after the log label for all log types.
         * 
         * @param sALabel The string to be logged after the log label.
         */
        LC_API void SetLogStringAfterLabelToAll(std::string_view sALabel);

        /**
         * @brief Sets the string to be logged after the log time for all log types.
         * 
         * @param sATime The string to be logged after the log time.
         */
        LC_API void SetLogStringAfterTimeToAll(std::string_view sATime);

        /**
         * @brief Sets the string to be logged after the log date for all log types.
         * 
         * @param sADate The string to be logged after the log date.
         */
        LC_API void SetLogStringAfterDateToAll(std::string_view sADate);

        /**
         * @brief Sets the string to be logged after the log function for all log types.
         * 
         * @param sAFunction The string to be logged after the log function.
         */
        LC_API void SetLogStringAfterFunctionToAll(std::string_view sAFunction);

        /**
         * @brief Sets the string to be logged after the log line for all log types.
         * 
         * @param sALine The string to be logged after the log line.
         */
        LC_API void SetLogStringAfterLineToAll(std::string_view sALine);

        /**
         * @brief Sets the string to be logged after the log message for all log types.
         * 
         * @param sAMessage The string to be logged after the log message.
         */
        LC_API void SetLogStringAfterMessageToAll(std::string_view sAMessage);

        /**
         * @brief Sets the string to be logged after the log file for all log types.
         * 
         * @param sAFile The string to be logged after the log file.
         */
        LC_API void SetLogStringAfterFileToAll(std::string_view sAFile);

        /**
         * @brief Sets the string to be logged after the log trace for all log types.
         * 
         * @param sATrace The string to be logged after the log trace.
         */
        LC_API void SetLogStringAfterTraceToAll(std::string_view sATrace);

        /**
         * @brief Sets the string to be logged before the trace function for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sBTraceFunction The string to be logged before the trace function.
         */
        LC_API void SetLogStringBeforeTraceFunction(std::string_view sLogType, std::string_view sBTraceFunction);

        /**
         * @brief Sets the string to be logged before the trace line for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sBTraceLine The string to be logged before the trace line.
         */
        LC_API void SetLogStringBeforeTraceLine(std::string_view sLogType, std::string_view sBTraceLine);

        /**
         * @brief Sets the string to be logged before the trace file for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sBTraceFile The string to be logged before the trace file.
         */
        LC_API void SetLogStringBeforeTraceFile(std::string_view sLogType, std::string_view sBTraceFile);

        /**
         * @brief Sets the string to be logged after the trace function for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sATraceFunction The string to be logged after the trace function.
         */
        LC_API void SetLogStringAfterTraceFunction(std::string_view sLogType, std::string_view sATraceFunction);

        /**
         * @brief Sets the string to be logged after the trace line for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sATraceLine The string to be logged after the trace line.
         */
        LC_API void SetLogStringAfterTraceLine(std::string_view sLogType, std::string_view sATraceLine);

        /**
         * @brief Sets the string to be logged after the trace file for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sATraceFile The string to be logged after the trace file.
         */
        LC_API void SetLogStringAfterTraceFile(std::string_view sLogType, std::string_view sATraceFile);

        /**
         * @brief Sets the string to be logged before the trace function for all log types.
         * 
         * @param sBTraceFunction The string to be logged before the trace function.
         */
        LC_API void SetLogStringBeforeTraceFunctionToAll(std::string_view sBTraceFunction);

        /**
         * @brief Sets the string to be logged before the trace line for all log types.
         * 
         * @param sBTraceLine The string to be logged before the trace line.
         */
        LC_API void SetLogStringBeforeTraceLineToAll(std::string_view sBTraceLine);

        /**
         * @brief Sets the string to be logged before the trace file for all log types.
         * 
         * @param sBTraceFile The string to be logged before the trace file.
         */
        LC_API void SetLogStringBeforeTraceFileToAll(std::string_view sBTraceFile);

        /**
         * @brief Sets the string to be logged after the trace function for all log types.
         * 
         * @param sATraceFunction The string to be logged after the trace function.
         */
        LC_API void SetLogStringAfterTraceFunctionToAll(std::string_view sATraceFunction);

        /**
         * @brief Sets the string to be logged after the trace line for all log types.
         * 
         * @param sATraceLine The string to be logged after the trace line.
         */
        LC_API void SetLogStringAfterTraceLineToAll(std::string_view sATraceLine);

        /**
         * @brief Sets the string to be logged after the trace file for all log types.
         * 
         * @param sATraceFile The string to be logged after the trace file.
         */
        LC_API void SetLogStringAfterTraceFileToAll(std::string_view sATraceFile);

        /**
         * @brief Sets the leftover string to be logged for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sLeftOver The leftover string to be logged.
         */
        LC_API void SetLogStringLeftOver(std::string_view sLogType, std::string_view sLeftOver);

        /**
         * @brief Sets the leftover string to be logged for all log types.
         * 
         * @param sLeftOver The leftover string to be logged.
         */
        LC_API void SetLogStringLeftOverToAll(std::string_view sLeftOver);

        /**
         * @brief Sets the leftover trace string to be logged for a given log type.
         * 
         * @param sLogType The type of log.
         * @param sLeftOverTrace The leftover trace string to be logged.
         */
        LC_API void SetLogStringLeftOverTrace(std::string_view sLogType, std::string_view sLeftOverTrace);

        /**
         * @brief Sets the leftover trace string to be logged for all log types.
         * 
         * @param sLeftOverTrace The leftover trace string to be logged.
         */
        LC_API void SetLogStringLeftOverTraceToAll(std::string_view sLeftOverTrace);
    }

    /**
     * @brief Adds a new log type.
     * 
     * @param sLogType The type of log to add.
     * @return True if the log type was added successfully, false otherwise.
     */
    LC_API bool AddLogType(std::string_view sLogType);

    /**
     * @brief Removes an existing log type.
     * 
     * @param sLogType The type of log to remove.
     * @return True if the log type was removed successfully, false otherwise.
     */
    LC_API bool RemoveLogType(std::string_view sLogType);

    /**
     * @brief Sets whether to write logs to a file for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogToFile Whether to write logs to a file.
     */
    LC_API void SetWriteToFile(std::string_view sLogType, bool bLogToFile);

    /**
     * @brief Sets whether to write logs to a file for all log types.
     * 
     * @param bLogToFile Whether to write logs to a file.
     */
    LC_API void SetWriteToFileToAll(bool bLogToFile);

    /**
     * @brief Sets whether to write logs to the console for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogToConsole Whether to write logs to the console.
     */
    LC_API void SetWriteToConsole(std::string_view sLogType, bool bLogToConsole);

    /**
     * @brief Sets whether to write logs to the console for all log types.
     * 
     * @param bLogToConsole Whether to write logs to the console.
     */
    LC_API void SetWriteToConsoleToAll(bool bLogToConsole);

    /**
     * @brief Sets whether to log the time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogTime Whether to log the time.
     */
    LC_API void SetLogTime(std::string_view sLogType, bool bLogTime);

    /**
     * @brief Sets whether to log the time for all log types.
     * 
     * @param bLogTime Whether to log the time.
     */
    LC_API void SetLogTimeToAll(bool bLogTime);

    /**
     * @brief Sets whether to log the date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogDate Whether to log the date.
     */
    LC_API void SetLogDate(std::string_view sLogType, bool bLogDate);

    /**
     * @brief Sets whether to log the date for all log types.
     * 
     * @param bLogDate Whether to log the date.
     */
    LC_API void SetLogDateToAll(bool bLogDate);

    /**
     * @brief Sets whether to log the function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogFunction Whether to log the function name.
     */
    LC_API void SetLogFunction(std::string_view sLogType, bool bLogFunction);

    /**
     * @brief Sets whether to log the function name for all log types.
     * 
     * @param bLogFunction Whether to log the function name.
     */
    LC_API void SetLogFunctionToAll(bool bLogFunction);

    /**
     * @brief Sets whether to log the line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogLine Whether to log the line number.
     */
    LC_API void SetLogLine(std::string_view sLogType, bool bLogLine);

    /**
     * @brief Sets whether to log the line number for all log types.
     * 
     * @param bLogLine Whether to log the line number.
     */
    LC_API void SetLogLineToAll(bool bLogLine);

    /**
     * @brief Sets whether to log the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogLevel Whether to log the log level.
     */
    LC_API void SetLogLevel(std::string_view sLogType, bool bLogLevel);

    /**
     * @brief Sets whether to log the log level for all log types.
     * 
     * @param bLogLevel Whether to log the log level.
     */
    LC_API void SetLogLevelToAll(bool bLogLevel);

    /**
     * @brief Sets whether to log the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogLabel Whether to log the log label.
     */
    LC_API void SetLogMessage(std::string_view sLogType, bool bLogMessage);

    /**
     * @brief Sets whether to log the log label for all log types.
     * 
     * @param bLogMessage Whether to log the log label.
     */
    LC_API void SetLogMessageToAll(bool bLogMessage);

    /**
     * @brief Sets whether to log the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogFile Whether to log the log file name.
     */
    LC_API void SetLogFile(std::string_view sLogType, bool bLogFile);

    /**
     * @brief Sets whether to log the log file name for all log types.
     * 
     * @param bLogFile Whether to log the log file name.
     */
    LC_API void SetLogFileToAll(bool bLogFile);

    /**
     * @brief Sets whether to log the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bLogTrace Whether to log the log trace.
     */
    LC_API void SetLogTrace(std::string_view sLogType, bool bLogTrace);

    /**
     * @brief Sets whether to log the log trace for all log types.
     * 
     * @param bLogTrace Whether to log the log trace.
     */
    LC_API void SetLogTraceToAll(bool bLogTrace);

    /**
     * @brief Sets the log file path for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sLogFilePath The log file path.
     */
    LC_API void SetLogFilePath(std::string_view sLogType, std::string_view sLogFilePath);

    /**
     * @brief Sets the log file path for all log types.
     * 
     * @param sLogFilePath The log file path.
     */
    LC_API void SetLogTimeFormat(std::string_view sLogType, std::string_view sLogTimeFormat);

    /**
     * @brief Sets the log time format for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sLogTimeFormat The log time format.
     */
    LC_API void SetLogDateFormat(std::string_view sLogType, std::string_view sLogDateFormat);

    /**
     * @brief Sets whether to color the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorLevel Whether to color the log level.
     */
    LC_API void SetLogColorLevel(std::string_view sLogType, bool bColorLevel);

    /**
     * @brief Sets whether to color the log level for all log types.
     * 
     * @param bColorLevel Whether to color the log level.
     */
    LC_API void SetLogColorLevelToAll(bool bColorLevel);

    /**
     * @brief Sets whether to color the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorLabel Whether to color the log label.
     */
    LC_API void SetLogColorLabel(std::string_view sLogType, bool bColorLabel);

    /**
     * @brief Sets whether to color the log label for all log types.
     * 
     * @param bColorLabel Whether to color the log label.
     */
    LC_API void SetLogColorLabelToAll(bool bColorLabel);

    /**
     * @brief Sets whether to color the log time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorTime Whether to color the log time.
     */
    LC_API void SetLogColorTime(std::string_view sLogType, bool bColorTime);

    /**
     * @brief Sets whether to color the log time for all log types.
     * 
     * @param bColorTime Whether to color the log time.
     */
    LC_API void SetLogColorTimeToAll(bool bColorTime);

    /**
     * @brief Sets whether to color the log date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorDate Whether to color the log date.
     */
    LC_API void SetLogColorDate(std::string_view sLogType, bool bColorDate);

    /**
     * @brief Sets whether to color the log date for all log types.
     * 
     * @param bColorDate Whether to color the log date.
     */
    LC_API void SetLogColorDateToAll(bool bColorDate);

    /**
     * @brief Sets whether to color the log function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorFunction Whether to color the log function name.
     */
    LC_API void SetLogColorFunction(std::string_view sLogType, bool bColorFunction);

    /**
     * @brief Sets whether to color the log function name for all log types.
     * 
     * @param bColorFunction Whether to color the log function name.
     */
    LC_API void SetLogColorFunctionToAll(bool bColorFunction);

    /**
     * @brief Sets whether to color the log line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorLine Whether to color the log line number.
     */
    LC_API void SetLogColorLine(std::string_view sLogType, bool bColorLine);

    /**
     * @brief Sets whether to color the log line number for all log types.
     * 
     * @param bColorLine Whether to color the log line number.
     */
    LC_API void SetLogColorLineToAll(bool bColorLine);

    /**
     * @brief Sets whether to color the log message for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorMessage Whether to color the log message.
     */
    LC_API void SetLogColorMessage(std::string_view sLogType, bool bColorMessage);

    /**
     * @brief Sets whether to color the log message for all log types.
     * 
     * @param bColorMessage Whether to color the log message.
     */
    LC_API void SetLogColorMessageToAll(bool bColorMessage);

    /**
     * @brief Sets whether to color the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorFile Whether to color the log file name.
     */
    LC_API void SetLogColorFile(std::string_view sLogType, bool bColorFile);

    /**
     * @brief Sets whether to color the log file name for all log types.
     * 
     * @param bColorFile Whether to color the log file name.
     */
    LC_API void SetLogColorFileToAll(bool bColorFile);

    /**
     * @brief Sets whether to color the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param bColorTrace Whether to color the log trace.
     */
    LC_API void SetLogColorTrace(std::string_view sLogType, bool bColorTrace);

    /**
     * @brief Sets whether to color the log trace for all log types.
     * 
     * @param bColorTrace Whether to color the log trace.
     */
    LC_API void SetLogColorTraceToAll(bool bColorTrace);

    /**
     * @brief Sets the color of the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log level.
     */
    LC_API void SetLogColorLevel(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log label.
     */
    LC_API void SetLogColorLabel(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log time.
     */
    LC_API void SetLogColorTime(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log date.
     */
    LC_API void SetLogColorDate(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log function name.
     */
    LC_API void SetLogColorFunction(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log line number.
     */
    LC_API void SetLogColorLine(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log message for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log message.
     */
    LC_API void SetLogColorMessage(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log file name.
     */
    LC_API void SetLogColorFile(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sColor The color of the log trace.
     */
    LC_API void SetLogColorTrace(std::string_view sLogType, std::string_view sColor);

    /**
     * @brief Sets the color of the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log level.
     */
    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log label.
     */
    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log time.
     */
    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log date.
     */
    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log function name.
     */
    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log line number.
     */
    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log message for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log message.
     */
    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log file name.
     */
    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log trace.
     */
    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color);

    /**
     * @brief Sets the color of the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log level.
     * @param effects The effects of the log level.
     */
    LC_API void SetLogColorLevel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log label.
     * @param effects The effects of the log label.
     */
    LC_API void SetLogColorLabel(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);
    
    /**
     * @brief Sets the color of the log time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log time.
     * @param effects The effects of the log time.
     */
    LC_API void SetLogColorTime(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log date.
     * @param effects The effects of the log date.
     */
    LC_API void SetLogColorDate(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log function name.
     * @param effects The effects of the log function name.
     */
    LC_API void SetLogColorFunction(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log line number.
     * @param effects The effects of the log line number.
     */
    LC_API void SetLogColorLine(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log message for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log message.
     * @param effects The effects of the log message.
     */
    LC_API void SetLogColorMessage(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log file name.
     * @param effects The effects of the log file name.
     */
    LC_API void SetLogColorFile(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param color The color of the log trace.
     * @param effects The effects of the log trace.
     */
    LC_API void SetLogColorTrace(std::string_view sLogType, LogColor color, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log level for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log level.
     */
    LC_API void SetLogColorLevel(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log label for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log label.
     */
    LC_API void SetLogColorLabel(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log time for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log time.
     */
    LC_API void SetLogColorTime(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log date for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log date.
     */
    LC_API void SetLogColorDate(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log function name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log function name.
     */
    LC_API void SetLogColorFunction(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log line number for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log line number.
     */
    LC_API void SetLogColorLine(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log message for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log message.
     */
    LC_API void SetLogColorMessage(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log file name for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log file name.
     */
    LC_API void SetLogColorFile(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the color of the log trace for a given log type.
     * 
     * @param sLogType The type of log.
     * @param effects The effects of the log trace.
     */
    LC_API void SetLogColorTrace(std::string_view sLogType, const std::vector<LogEffect>& effects);

    /**
     * @brief Sets the log order for a given log type.
     * 
     * @param sLogType The type of log.
     * @param logOrder The order of log components.
     */
    LC_API void SetLogOrder(std::string_view sLogType, std::vector<LogOrder> logOrder);

    /**
     * @brief Sets the log order for a given log type.
     * 
     * @param sLogType The type of log.
     * @param logOrder The order of log components.
     */
    LC_API void SetLogOrder(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);

    /**
     * @brief Sets the log order for all log types.
     * 
     * @param logOrder The order of log components.
     */
    LC_API void SetLogOrderToAll(std::vector<LogOrder> logOrder);

    /**
     * @brief Sets the log order for all log types.
     * 
     * @param logOrder The order of log components.
     */
    LC_API void SetLogOrderToAll(std::initializer_list<LogOrder> logOrder);

    /**
     * @brief Sets the trace log order for a given log type.
     * 
     * @param sLogType The type of log.
     * @param logOrder The order of trace log components.
     */
    LC_API void SetLogOrderTrace(std::string_view sLogType, std::vector<LogOrder> logOrder);

    /**
     * @brief Sets the trace log order for a given log type.
     * 
     * @param sLogType The type of log.
     * @param logOrder The order of trace log components.
     */
    LC_API void SetLogOrderTrace(std::string_view sLogType, std::initializer_list<LogOrder> logOrder);

    /**
     * @brief Sets the trace log order for all log types.
     * 
     * @param logOrder The order of trace log components.
     */
    LC_API void SetLogOrderTraceToAll(std::vector<LogOrder> logOrder);

    /**
     * @brief Sets the trace log order for all log types.
     * 
     * @param logOrder The order of trace log components.
     */
    LC_API void SetLogOrderTraceToAll(std::initializer_list<LogOrder> logOrder);

    /**
     * @brief Sets the format trim for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sFormatTrim The format trim string.
     */
    LC_API void SetFormatTrim(std::string_view sLogType, std::string_view sFormatTrim);

    /**
     * @brief Sets the format trim for all log types.
     * 
     * @param sFormatTrim The format trim string.
     */
    LC_API void SetFormatTrimToAll(std::string_view sFormatTrim);

    /**
     * @brief Sets the format for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sFormat The format string.
     */
    LC_API void SetFormat(std::string_view sLogType, std::string_view sFormat);

    /**
     * @brief Sets the format for all log types.
     * 
     * @param sFormat The format string.
     */
    LC_API void SetFormatToAll(std::string_view sFormat);

    /**
     * @brief Sets the trace format for a given log type.
     * 
     * @param sLogType The type of log.
     * @param sFormat The trace format string.
     */
    LC_API void SetFormatTrace(std::string_view sLogType, std::string_view sFormat);

    /**
     * @brief Sets the trace format for all log types.
     * 
     * @param sFormat The trace format string.
     */
    LC_API void SetFormatTraceToAll(std::string_view sFormat);
}