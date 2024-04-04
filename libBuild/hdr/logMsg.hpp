#pragma once

#include <string>
#include <cstdint>
#include <format>
#include <source_location>

#include "defines.hpp"

namespace lc
{
    struct LOGCRAFT_API LogMsg
    {
        std::string m_strMsg                    = "";
        std::string m_sLevel                    = "";
        std::string m_sLabel                    = "";
        std::source_location m_sourceLocation   = {};
        std::format_args m_args                 = {};
    };

    namespace internal
    {   
        template<typename... Args>
        LogMsg CreateLogMsg(std::string_view strMsg, std::string_view strLevel, std::string_view strLabel, const std::source_location& m_sourceLocation, Args&&... args)
        {
            return LogMsg
            {
                .m_strMsg = strMsg.data(),
                .m_sLevel = strLevel.data(),
                .m_sLabel = strLabel.data(),
                .m_sourceLocation = m_sourceLocation,
                .m_args = std::make_format_args(std::forward<Args>(args)...)
            };
        }
    }
}