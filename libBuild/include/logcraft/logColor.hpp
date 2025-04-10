#pragma once

#include <unordered_map>
#include <vector>
#include <sstream>

#include "defines.hpp"

namespace lc
{
    /** 
     * @brief Log color options
     * 
     * @note Defines various colors that can be used for log messages.
     */
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

    /** 
     * @brief Log effect options
     * 
     * @note Defines various text effects that can be applied to log messages.
     */
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
        /** 
         * @brief Create an ASCII escape sequence for log color and effects
         * 
         * @note Combines the specified color and effects into an escape sequence.
         */
        LC_API std::string CreateAsciiEscapeSequence(LogColor color, const std::vector<LogEffect> &effect);

        /** 
         * @brief Get the ASCII code for a log color
         * 
         * @note Returns the escape code for the specified color.
         */
        LC_API std::string GetColor(LogColor color);

        /** 
         * @brief Get the ASCII codes for log effects
         * 
         * @note Returns the escape codes for the specified effects.
         */
        LC_API std::string GetEffects(const std::vector<LogEffect> &effect);

        /** 
         * @brief Get the reset color code
         * 
         * @note Returns the escape code to reset the color.
         */
        LC_API std::string GetResetColor();
    }
}