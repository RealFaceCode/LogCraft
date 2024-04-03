#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"
#include "logColor.hpp"

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

        SetLogTypeOrderToAll(logOrder);

        SetLogTypeColorLevel("INFO", LogColor::White);
        SetLogTypeColorLevel("DEBUG", LogColor::Green);
        SetLogTypeColorLevel("WARNING", LogColor::Yellow);
        SetLogTypeColorLevel("ERROR", LogColor::Red);
        SetLogTypeColorLevel("CRITICAL", LogColor::LightMagenta, {LogEffect::Blink});
    }
}