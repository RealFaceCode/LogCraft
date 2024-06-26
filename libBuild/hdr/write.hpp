#pragma once

#include <string>
#include <string_view>
#include "backtrace.hpp"
#include "fileObserver.hpp"

#include "defines.hpp"

namespace lc::internal
{
    LC_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine, const Backtrace& bt, bool fileMode = false);
    LC_API void WriteToConsole(std::string_view sMessage);
    LC_API void WriteToFile(FileObserver& fOb, std::string_view sMessage);
}