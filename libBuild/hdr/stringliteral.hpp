#pragma once

#include <algorithm>

#include "defines.hpp"

namespace lc::internal
{
    template<size_t N>
    struct LC_API StringLiteral
    {
        constexpr StringLiteral(const char (&str)[N])
        {
            std::copy_n(str, N, value);
        }

        char value[N];
    };
}