#pragma once

#include <unordered_map>
#include <vector>
#include <sstream>

#include "defines.hpp"

namespace lc
{
    enum class LogColor
    {
        White,
        Black,
        Gray,
        LightRed,
        Red,
        LightGreen,
        Green,
        LightBlue,
        Blue,
        LightMagenta,
        Magenta,
        LightCyan,
        Cyan,
        LightYellow,
        Yellow,
        LightOrange,
        Orange,
        Reset
    };

    enum class LogEffect
    {
        Bold,
        Underline,
        Blink,
        Reverse,
        Conceal,
        CrossedOut
    };

    namespace internal
    {
        LOGCRAFT_API std::string CreateAsciiEscapeSequence(LogColor color, const std::vector<LogEffect> &effect);
        LOGCRAFT_API std::string GetColor(LogColor color);
        LOGCRAFT_API std::string GetEffects(const std::vector<LogEffect> &effect);
        LOGCRAFT_API std::string GetResetColor();
    }
}