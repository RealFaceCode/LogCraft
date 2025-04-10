#pragma once

#include <algorithm>

#include "defines.hpp"

namespace lc::internal
{
    /**
     * @brief A compile-time string literal.
     * 
     * @tparam N The size of the string literal.
     * 
     * @note This struct stores a string literal at compile time.
     */
    template<size_t N>
    struct LC_API StringLiteral
    {
        /**
         * @brief Constructs a StringLiteral from a C-style string.
         * 
         * @param str The C-style string.
         * 
         * @note This constructor copies the provided C-style string into the value array.
         */
        constexpr StringLiteral(const char (&str)[N])
        {
            std::copy_n(str, N, value);
        }

        char value[N];
    };
}