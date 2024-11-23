#include "lc.hpp"
#include "logConfig.hpp"
#include "logcraftConfig.hpp"
#include "logColor.hpp"
#include "msgServer.hpp"
#include "fileObserver.hpp"

namespace lc
{
    bool Init_LC = false;
    bool DeInit_LC = false;

    LC_API void Init()
    {
        if (Init_LC)
            return;

        Init_LC = true;
        DeInit_LC = false;

        AddLogType("INFO");
        AddLogType("DEBUG");
        AddLogType("WARNING");
        AddLogType("ERROR");
        AddLogType("CRITICAL");

        SetFormatTrimToAll("] }");
        SetFormatToAll("[{LEVEL}] [LABEL:{LABEL}] [{TIME} {DATE}] [{FUNC}] [LINE:{LINE}] {MSG}\n\tTrace:\n{TRACE}");
        SetFormatTraceToAll("\t\t{FILE}:{LINE} {FUNC}\n");

        SetLogColorLevel("INFO", LogColor::White);
        SetLogColorLevel("DEBUG", LogColor::Green);
        SetLogColorLevel("WARNING", LogColor::Yellow);
        SetLogColorLevel("ERROR", LogColor::Red);
        SetLogColorLevel("CRITICAL", LogColor::LightMagenta, {LogEffect::Blink});

        internal::StartMsgServer();
    }

    LC_API void DeInit()
    {
        if (DeInit_LC)
            return;

        DeInit_LC = true;
        Init_LC = false;
        
        internal::StopMsgServer();
        auto& fOb = internal::GetFileObserver();
        fOb.close();
    }
}