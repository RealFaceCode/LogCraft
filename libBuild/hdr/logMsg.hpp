#pragma once

#include <string>
#include <cstdint>
#include <format>
#include <source_location>

#include "defines.hpp"

namespace lc
{
    struct LC_API LogMsg
    {
        std::string m_strMsg                    = "";
        std::string m_sLevel                    = "";
        std::string m_sLabel                    = "";
        std::source_location m_sourceLocation   = {};
    };

    namespace internal
    {   
        template<typename... Args>
        LogMsg CreateLogMsg(std::string_view strMsg, std::string_view strLevel, std::string_view strLabel, const std::source_location& m_sourceLocation, const Args&... args)
        {
            return LogMsg {
                .m_strMsg = std::vformat(strMsg, std::make_format_args(args...)),
                .m_sLevel = strLevel.data(),
                .m_sLabel = strLabel.data(),
                .m_sourceLocation = m_sourceLocation,
            };
        }
    }
}