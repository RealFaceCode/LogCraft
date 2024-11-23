#pragma once

#include <cstdint>

#include "threadPool.hpp"
#include "defines.hpp"
#include "logMsg.hpp"

namespace lc
{
    struct FileObserver;

    namespace internal
    {
        /**
         * @brief Configuration for the message server.
         * 
         * @note This struct holds the configuration for the message server, including the maximum number of threads for terminal and file logging.
         */
        struct LC_API MsgServerConfig
        {
            std::size_t m_nMaxThreadsTerminal   = 2;
            std::size_t m_nMaxThreadsFile       = 1;
        };

        /**
         * @brief Starts the message server.
         * 
         * @note This function initializes and starts the message server.
         */
        LC_API void StartMsgServer();

        /**
         * @brief Stops the message server.
         * 
         * @note This function stops the message server.
         */
        LC_API void StopMsgServer();

        /**
         * @brief Gets the thread pool for terminal logging.
         * 
         * @return The thread pool for terminal logging.
         * 
         * @note This function returns the thread pool used for terminal logging.
         */
        LC_API eutil::ThreadPool<LogMsg>& GetThreadPoolTerminal();

        /**
         * @brief Gets the thread pool for file logging.
         * 
         * @return The thread pool for file logging.
         * 
         * @note This function returns the thread pool used for file logging.
         */
        LC_API eutil::ThreadPool<LogMsg>& GetThreadPoolFile();

        /**
         * @brief Gets the file observer.
         * 
         * @return The file observer.
         * 
         * @note This function returns the file observer used for file logging.
         */
        LC_API FileObserver& GetFileObserver();
    }

    /**
     * @brief Sets the maximum number of threads for terminal logging.
     * 
     * @param nThreads The number of threads.
     * 
     * @note This function sets the maximum number of threads used for terminal logging.
     */
    LC_API void SetMaxThreadsTerminal(std::size_t nThreads);

    /**
     * @brief Sets the maximum number of threads for file logging.
     * 
     * @param nThreads The number of threads.
     * 
     * @note This function sets the maximum number of threads used for file logging.
     */
    LC_API void SetMaxThreadsFile(std::size_t nThreads);
}