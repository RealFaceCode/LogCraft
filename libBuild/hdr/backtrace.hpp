#pragma once

#include "defines.hpp"

#include <string>
#include <vector>

namespace lc
{
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
        LC_API Backtrace GetBacktrace();
        LC_API void TrimFunctionName(Backtrace& bt);
        LC_API void TrimFile(Backtrace& bt);
        LC_API void DelAfterMain(Backtrace& bt);
    }
}