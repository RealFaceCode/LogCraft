#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"
#include "logColor.hpp"

namespace lc
{
    LOGCRAFT_API void Init()
    {
        AddLogType("INFO");
        AddLogType("DEBUG");
        AddLogType("WARNING");
        AddLogType("ERROR");
        AddLogType("CRITICAL");

        auto& orderSet = internal::GetAvailableOrders();
        orderSet = {"{LEVEL}", "{LABEL}", "{TIME}", "{DATE}", "{FUNC}", "{LINE}", "{MSG}"};

        SetFormatTrimToAll("] }");
        SetFormatToAll("[{LEVEL}] [LABEL:{LABEL}] [{TIME} {DATE}] [{FUNC}] [LINE:{LINE}] {MSG}");

        SetLogTypeColorLevel("INFO", LogColor::White);
        SetLogTypeColorLevel("DEBUG", LogColor::Green);
        SetLogTypeColorLevel("WARNING", LogColor::Yellow);
        SetLogTypeColorLevel("ERROR", LogColor::Red);
        SetLogTypeColorLevel("CRITICAL", LogColor::LightMagenta, {LogEffect::Blink});
    }
}