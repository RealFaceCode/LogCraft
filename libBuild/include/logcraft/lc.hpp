#pragma once
#include "defines.hpp"
#include "log.hpp"

namespace lc
{
    /**
     * @brief Initialize the logger
     * 
     * This function initializes the logger. It is required to call this function before using the logger.
     * 
     * @note This function is not thread-safe.
     */
    LC_API void Init();

    /**
     * @brief Deinitialize the logger
     * 
     * This function deinitializes the logger. It is required to call this function before the program ends.
     * 
     * @note This function is not thread-safe.
     */
    LC_API void DeInit();
}