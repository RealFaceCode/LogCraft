#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"

namespace lc
{
    LOGCRAFT_API void Init()
    {
        auto logCraftConfig = internal::GetLogCraftConfig();
        logCraftConfig = std::make_shared<internal::LogCraftConfig>();

        AddLogType("INFO");
        AddLogType("DEBUG");
        AddLogType("WARNING");
        AddLogType("ERROR");
        AddLogType("CRITICAL");

        std::initializer_list<LogOrder> logOrder = 
        {
            LogOrder::Level,
            LogOrder::Time,
            LogOrder::Date,
            LogOrder::Function, 
            LogOrder::Line, 
            LogOrder::Message
        };
        SetLogTypeOrder("INFO", logOrder);
        SetLogTypeOrder("DEBUG", logOrder);
        SetLogTypeOrder("WARNING", logOrder);
        SetLogTypeOrder("ERROR", logOrder);
        SetLogTypeOrder("CRITICAL", logOrder);
    }
}