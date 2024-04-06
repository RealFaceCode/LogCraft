#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"
#include "logColor.hpp"
#include "msgServer.hpp"

namespace lc
{
    LC_API void Init()
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

        SetLogColorLevel("INFO", LogColor::White);
        SetLogColorLevel("DEBUG", LogColor::Green);
        SetLogColorLevel("WARNING", LogColor::Yellow);
        SetLogColorLevel("ERROR", LogColor::Red);
        SetLogColorLevel("CRITICAL", LogColor::LightMagenta, {LogEffect::Blink});

        internal::SartMsgServer();
    }
}