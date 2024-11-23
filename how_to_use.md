## Initialization

Before using the logger, you need to initialize it. This is done by calling the Init function. Make sure to call this function before any logging operations.

```cpp
#include "lc.hpp"

int main() {
    lc::Init();
    // Your code here
    lc::DeInit();
    return 0;
}
```

## Logging Messages

### Logging with a Label

To log a message with a specific label, use the Log function template with the label as a template parameter.

```cpp
#include "lc.hpp"

int main() {
    lc::Init();

    lc::Log<"MyLabel">("INFO", "This is a log message with a label");

    lc::DeInit();
    return 0;
}
```

### Logging without a Label

To log a message without a specific label, use the Log function template without the label parameter.

```cpp
#include "lc.hpp"

int main() {
    lc::Init();

    lc::Log("INFO", "This is a log message without a label");

    lc::DeInit();
    return 0;
}
```

## Configuration

### Adding Log Types

You can add new log types for logging:

```cpp
lc::AddLogType("default");
```

### Setting Log Colors

You can also set the colors for different log components. For example, to set the color of the log level:

```cpp
lc::SetLogColorLevel("default", lc::LogColor::Red);
```

### Setting Log Formats

To set the format of log messages:

```cpp
ls::SetFormatToAll("[{LEVEL}] [LABEL:{LABEL}] [{TIME} {DATE}] [{FUNC}] [LINE:{LINE}] {MSG}\n\tTrace:\n{TRACE}");
```

## Deinitialization

Before your program ends, make sure to deinitialize the logger by calling the DeInit function.

```cpp
#include "lc.hpp"

int main() {
    lc::Init();

    // Your code here

    lc::DeInit();
    return 0;
}
```

By following these instructions, you can effectively use the logger in your application.
