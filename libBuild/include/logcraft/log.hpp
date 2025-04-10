#pragma once

#include "defines.hpp"
#include "stringLiteral.hpp"
#include "msgLiteral.hpp"
#include "msgServer.hpp"
#include "logMsg.hpp"

namespace lc
{
    /**
     * @brief Logs a message with a specified label.
     * 
     * @tparam Label The label for the log message.
     * @tparam Args The types of the arguments to be logged.
     * @param sLevel The severity level of the log message.
     * @param msg The message literal to be logged.
     * @param args The arguments to be logged.
     * 
     * @note This function pushes the log message to both the terminal and file thread pools.
     */
    template<internal::StringLiteral Label, typename... Args>
    void Log(std::string_view sLevel, internal::MsgLiteral msg, const Args&... args)
    {
        auto& tpt = internal::GetThreadPoolTerminal();
        auto& tpf = internal::GetThreadPoolFile();

        auto logMsg = internal::CreateLogMsg(msg.m_strMsg, sLevel, Label.value, msg.m_sourceLocation, args...);
        tpt.push(logMsg);
        tpf.push(logMsg);
    }

    /**
     * @brief Logs a message without a specified label.
     * 
     * @tparam Args The types of the arguments to be logged.
     * @param sLevel The severity level of the log message.
     * @param msg The message literal to be logged.
     * @param args The arguments to be logged.
     * 
     * @note This function pushes the log message to both the terminal and file thread pools.
     */
    template<typename... Args>
    void Log(std::string_view sLevel, internal::MsgLiteral msg, const Args&... args)
    {
        auto& tpt = internal::GetThreadPoolTerminal();
        auto& tpf = internal::GetThreadPoolFile();

        auto logMsg = internal::CreateLogMsg(msg.m_strMsg, sLevel, "", msg.m_sourceLocation, args...);
        tpt.push(logMsg);
        tpf.push(logMsg);
    }
}