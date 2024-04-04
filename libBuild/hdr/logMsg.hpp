#pragma once

#include <string>
#include <cstdint>
#include <format>

#include "defines.hpp"

namespace lc
{
    struct LOGCRAFT_API LogMsg
    {
        std::string m_strMsg        = "";
        std::string m_sLevel        = "";
        std::string m_sLabel        = "";
        std::string m_strFile       = "";
        std::string m_strFunction   = "";
        std::size_t m_nLine         = 0;
        std::format_args m_args     = {};
    };

    namespace internal
    {   
        template<typename... Args>
        LogMsg LOGCRAFT_API CreateLogMsg(std::string_view strMsg, std::string_view strLevel, std::string_view strLabel, std::string_view strFile, std::string_view strFunction, std::size_t nLine, Args&&... args)
        {
            return LogMsg
            {
                .m_strMsg = strMsg,
                .m_sLevel = strLevel,
                .m_sLabel = strLabel,
                .m_strFile = strFile,
                .m_strFunction = strFunction,
                .m_nLine = nLine,
                .m_args = std::make_format_args(std::forward<Args>(args)...)
            };
        }
    }
}