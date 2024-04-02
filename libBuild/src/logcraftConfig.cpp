#include "logcraftConfig.hpp"

namespace lc::internal
{
    std::shared_ptr<LogCraftConfig> g_logCraftConfig = nullptr;

    std::shared_ptr<LogCraftConfig> GetLogCraftConfig()
    {
        return g_logCraftConfig;
    }
}