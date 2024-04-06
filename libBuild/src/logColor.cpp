#include "logColor.hpp"

#include "unordered_map"

namespace lc
{
    std::unordered_map<LogColor, std::string> g_mapColor
    {
        {LogColor::White,           "\033[0;37m"},
        {LogColor::Black,           "\033[0;30m"},
        {LogColor::Gray,            "\033[1;30m"},
        {LogColor::LightRed,        "\033[1;31m"},
        {LogColor::Red,             "\033[0;31m"},
        {LogColor::LightGreen,      "\033[1;32m"},
        {LogColor::Green,           "\033[0;32m"},
        {LogColor::LightBlue,       "\033[1;34m"},
        {LogColor::Blue,            "\033[0;34m"},
        {LogColor::LightMagenta,    "\033[1;35m"},
        {LogColor::Magenta,         "\033[0;35m"},
        {LogColor::LightCyan,       "\033[1;36m"},
        {LogColor::Cyan,            "\033[0;36m"},
        {LogColor::LightYellow,     "\033[1;33m"},
        {LogColor::Yellow,          "\033[0;33m"},
        {LogColor::LightOrange,     "\033[1;33m"},
        {LogColor::Orange,          "\033[0;33m"},
        {LogColor::Reset,           "\033[0m"}
    };

    std::unordered_map<LogEffect, std::string> g_mapEffect
    {
        {LogEffect::Bold,           "\033[1m"},
        {LogEffect::Underline,      "\033[4m"},
        {LogEffect::Blink,          "\033[5m"},
        {LogEffect::Reverse,        "\033[7m"},
        {LogEffect::Conceal,        "\033[8m"},
        {LogEffect::CrossedOut,     "\033[9m"}
    };

    namespace internal
    {
        LC_API std::string CreateAsciiEscapeSequence(LogColor color, const std::vector<LogEffect> &effect)
        {
            std::stringbuf buffer;
            auto& colorStr = g_mapColor[color];

            buffer.sputn(colorStr.data(), colorStr.size());

            for(auto e : effect)
            {
                auto& effectStr = g_mapEffect[e];
                buffer.sputn(effectStr.data(), effectStr.size());
            }

            return buffer.str();
        }

        LC_API std::string GetColor(LogColor color)
        {
            return g_mapColor[color];
        }

        LC_API std::string GetEffects(const std::vector<LogEffect> &effect)
        {
            std::stringbuf buffer;

            for(auto e : effect)
            {
                auto& effectStr = g_mapEffect[e];
                buffer.sputn(effectStr.data(), effectStr.size());
            }

            return buffer.str();
        }

        LC_API std::string GetResetColor()
        {
            return g_mapColor[LogColor::Reset];
        }
    }
}