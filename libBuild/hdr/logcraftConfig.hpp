#pragma once

#include <memory>

#include "defines.hpp"

namespace lc::internal
{
    struct LOGCRAFT_API LogCraftConfig
    {};

    LOGCRAFT_API std::shared_ptr<LogCraftConfig> GetLogCraftConfig();
}