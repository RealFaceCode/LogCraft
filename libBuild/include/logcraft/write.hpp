#pragma once

#include <string>
#include <string_view>
#include "backtrace.hpp"
#include "fileObserver.hpp"

#include "defines.hpp"

namespace lc::internal
{
    /**
     * @brief Builds a log message.
     * 
     * @param sLevel The log level.
     * @param sLabel The log label.
     * @param sMessage The log message.
     * @param sFunction The function name.
     * @param sFile The file name.
     * @param nLine The line number.
     * @param bt The backtrace object.
     * @param fileMode Whether the message is for file mode.
     * @return The constructed log message.
     * 
     * @note This function constructs a log message with the provided details.
     */
    LC_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine, const Backtrace& bt, bool fileMode = false);

    /**
     * @brief Writes a message to the console.
     * 
     * @param sMessage The message to write.
     * 
     * @note This function outputs the provided message to the console.
     */
    LC_API void WriteToConsole(std::string_view sMessage);

    /**
     * @brief Writes a message to a file.
     * 
     * @param fOb The file observer.
     * @param sMessage The message to write.
     * 
     * @note This function outputs the provided message to a file using the file observer.
     */
    LC_API void WriteToFile(FileObserver& fOb, std::string_view sMessage);
}