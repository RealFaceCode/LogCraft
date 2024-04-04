#pragma once

#include "defines.hpp"
#include "stringLiteral.hpp"
#include "msgLiteral.hpp"
#include "msgServer.hpp"
#include "logMsg.hpp"

namespace lc
{

    template<internal::StringLiteral Label,typename... Args>
    void Log(std::string_view sLevel, internal::MsgLiteral msg, const Args&... args)
    {
        auto& tp = internal::GetThreadPool();

        auto logMsg = internal::CreateLogMsg(msg.m_strMsg, sLevel, Label.value, msg.m_sourceLocation, args...);
        tp.push(logMsg);
    }
}