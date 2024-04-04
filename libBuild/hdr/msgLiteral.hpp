#pragma once

#include <source_location>
#include <string>

#include "defines.hpp"

namespace lc::internal
{
    struct LOGCRAFT_API MsgLiteral
    {
    public:
        LOGCRAFT_API MsgLiteral(std::string_view strMsg, std::source_location sourceLocation = std::source_location::current());

        std::string_view m_strMsg;
        std::source_location m_sourceLocation;
    };
}