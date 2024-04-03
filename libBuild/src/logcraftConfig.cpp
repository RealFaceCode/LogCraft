#include "logcraftConfig.hpp"

namespace lc
{
    namespace internal
    {
        LogCraftConfig g_logCraftConfig;

        LOGCRAFT_API LogCraftConfig& GetLogCraftConfig()
        {
            return g_logCraftConfig;
        }
    }

    LOGCRAFT_API void SetAllignLevel(bool bAllignLeft)
    {
        internal::g_logCraftConfig.m_bAllignLeft = bAllignLeft;
    }

}