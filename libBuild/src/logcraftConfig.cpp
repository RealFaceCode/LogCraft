#include "logcraftConfig.hpp"

namespace lc
{
    namespace internal
    {
        std::shared_ptr<LogCraftConfig> g_logCraftConfig = nullptr;

        LOGCRAFT_API std::shared_ptr<LogCraftConfig>& GetLogCraftConfig()
        {
            return g_logCraftConfig;
        }
    }

    LOGCRAFT_API void SetAllignLevel(bool bAllignLeft)
    {
        auto config = internal::GetLogCraftConfig();
        if(config)
            config->m_bAllignLeft = bAllignLeft;
    }

}