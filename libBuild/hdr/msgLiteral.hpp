#pragma once

#include <source_location>
#include <string>

#include "defines.hpp"

namespace lc::internal
{
    struct LOGCRAFT_API MsgLiteral
    {
    public:
        MsgLiteral () = default;
        MsgLiteral(std::string_view strMsg, std::source_location sourceLocation = std::source_location::current());
        MsgLiteral(const std::string& strMsg, std::source_location sourceLocation = std::source_location::current());
        MsgLiteral(const char* strMsg, std::source_location sourceLocation = std::source_location::current());

        std::string_view m_strMsg;
        std::source_location m_sourceLocation;
    };
}