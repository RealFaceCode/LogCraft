#pragma once

#include "defines.hpp"

#include <string>
#include <vector>

namespace lc
{
    /**
     * @brief Holds information about a backtrace.
     * 
     * @note This struct stores function names, file names, and line numbers of a backtrace.
     */
    struct LC_API Backtrace
    {
    public:
        Backtrace() = default;
        ~Backtrace() = default;

        std::vector<std::string> m_sFunctionNames;
        std::vector<std::string> m_sFileNames;
        std::vector<std::int64_t> m_nLineNumbers;
    };

    namespace internal
    {
        /**
         * @brief Retrieves the current backtrace.
         * 
         * @return A Backtrace object containing the current backtrace information.
         */
        LC_API Backtrace GetBacktrace();
        /**
         * @brief Trims the function names in the backtrace.
         * 
         * @param bt The Backtrace object to be trimmed.
         */
        LC_API void TrimFunctionName(Backtrace& bt);
        /**
         * @brief Trims the file names in the backtrace.
         * 
         * @param bt The Backtrace object to be trimmed.
         */
        LC_API void TrimFile(Backtrace& bt);
        /**
         * @brief Deletes entries in the backtrace after the main function.
         * 
         * @param bt The Backtrace object to be modified.
         */
        LC_API void DelAfterMain(Backtrace& bt);
    }
}