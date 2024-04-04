#include "msgLiteral.hpp"

namespace lc::internal
{
    LOGCRAFT_API MsgLiteral::MsgLiteral(std::string_view strMsg, std::source_location sourceLocation)
        : m_strMsg(strMsg), m_sourceLocation(sourceLocation)
    {}
}