#pragma once

#define LC_VERSION_MAJOR 0
#define LC_VERSION_MINOR 1
#define LC_VERSION_PATCH 0

#ifdef LOGCRAFT_EXPORTS
    #define LOGCRAFT_API __declspec(dllexport)
#else
    #define LOGCRAFT_API __declspec(dllimport)
#endif