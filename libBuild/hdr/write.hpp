#pragma once

#include <string>
#include <string_view>

#include "defines.hpp"
#include <format>

namespace lc::internal
{
    LOGCRAFT_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine, bool fileMode = false);
    LOGCRAFT_API void WriteToConsole(std::string_view sMessage);
    LOGCRAFT_API void WriteToFile(std::string_view sMessage);
}