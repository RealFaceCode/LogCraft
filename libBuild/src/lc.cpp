#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"
#include "logColor.hpp"
#include "msgServer.hpp"
#include "fileObserver.hpp"

namespace lc
{
    LC_API void Init()
    {
        AddLogType("INFO");
        AddLogType("DEBUG");
        AddLogType("WARNING");
        AddLogType("ERROR");
        AddLogType("CRITICAL");

        SetFormatTrimToAll("] }");
        SetFormatToAll("[{LEVEL}] [LABEL:{LABEL}] [{TIME} {DATE}] [{FUNC}] [LINE:{LINE}] {MSG}\n\tTrace:\n\t\t{TRACE}");
        SetFormatTraceToAll("{FILE}:{LINE} {FUNC}\n");

        SetLogColorLevel("INFO", LogColor::White);
        SetLogColorLevel("DEBUG", LogColor::Green);
        SetLogColorLevel("WARNING", LogColor::Yellow);
        SetLogColorLevel("ERROR", LogColor::Red);
        SetLogColorLevel("CRITICAL", LogColor::LightMagenta, {LogEffect::Blink});

        internal::SartMsgServer();
    }

    LC_API void DeInit()
    {
        internal::StopMsgServer();
        auto& fOb = internal::GetFileObserver();
        fOb.close();
    }
}