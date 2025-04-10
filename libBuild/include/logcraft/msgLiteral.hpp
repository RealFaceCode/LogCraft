#pragma once

#include <source_location>
#include <string>

#include "defines.hpp"

namespace lc::internal
{
    /**
     * @brief Represents a log message with source location.
     * 
     * @note This struct holds a log message along with its source location information.
     */
    struct LC_API MsgLiteral
    {
    public:
        MsgLiteral () = default;

        /**
         * @brief Constructs a MsgLiteral from a string view.
         * 
         * @param strMsg The log message.
         * @param sourceLocation The source location (default is current location).
         * 
         * @note This constructor initializes the log message and source location.
         */
        MsgLiteral(std::string_view strMsg, std::source_location sourceLocation = std::source_location::current());

        /**
         * @brief Constructs a MsgLiteral from a string.
         * 
         * @param strMsg The log message.
         * @param sourceLocation The source location (default is current location).
         * 
         * @note This constructor initializes the log message and source location.
         */
        MsgLiteral(const std::string& strMsg, std::source_location sourceLocation = std::source_location::current());

        /**
         * @brief Constructs a MsgLiteral from a C-style string.
         * 
         * @param strMsg The log message.
         * @param sourceLocation The source location (default is current location).
         * 
         * @note This constructor initializes the log message and source location.
         */
        MsgLiteral(const char* strMsg, std::source_location sourceLocation = std::source_location::current());

        std::string_view m_strMsg;
        std::source_location m_sourceLocation;
    };
}