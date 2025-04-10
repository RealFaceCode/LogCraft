#include "logcraft/msgLiteral.hpp"

namespace lc::internal
{
    LC_API MsgLiteral::MsgLiteral(std::string_view strMsg, std::source_location sourceLocation)
    : m_strMsg(strMsg), m_sourceLocation(sourceLocation)
    {}

    LC_API MsgLiteral::MsgLiteral(const std::string& strMsg, std::source_location sourceLocation)
    : m_strMsg(strMsg), m_sourceLocation(sourceLocation)
    {}

    LC_API MsgLiteral::MsgLiteral(const char* strMsg, std::source_location sourceLocation)
    : m_strMsg(strMsg), m_sourceLocation(sourceLocation)
    {}

}