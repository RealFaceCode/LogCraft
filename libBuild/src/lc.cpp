#include "lc.hpp"
#include "logConfig.hpp"

namespace lc
{
    void Init()
    {
        AddLogType("INFO");
        AddLogType("DEBUG");
        AddLogType("WARNING");
        AddLogType("ERROR");
        AddLogType("CRITICAL");
    }
}