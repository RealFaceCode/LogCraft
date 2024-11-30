cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME LogCraft)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

if(NOT DEFINED PARENT_SET)
    set(PARENT_SET TRUE)
    set(BUILD_EXAMPLES $ENV{LOGCRAFT_BUILD_EXAMPLES})
    set(BUILD_TESTING ${BUILD_EXAMPLES})
else()
    set(BUILD_EXAMPLES FALSE)
    set(BUILD_TESTING FALSE)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES 0)

if(${BUILD_EXAMPLES})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS  "libBuild/src/*.cpp")

include(FetchContent)

set(EUTIL_LIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/eUtil")

if(NOT EXISTS "${EUTIL_LIB_DIR}/CMakeLists.txt")
    message(STATUS "Library 'eUtil' not found. Fetching...")

    FetchContent_Declare(
        eUtil
        GIT_REPOSITORY https://github.com/RealFaceCode/eUtil.git
        GIT_TAG main
        SOURCE_DIR ${EUTIL_LIB_DIR}
    )

    if(NOT eUtil_POPULATED)
        FetchContent_Populate(eUtil)
    endif()

    message(STATUS "Library 'eUtil' fetched.")
else()
    message(STATUS "Library 'eUtil' already exists.")
    message(STATUS "Try to fetch updates...")

    execute_process(
        COMMAND git pull
        WORKING_DIRECTORY ${EUTIL_LIB_DIR}
    )
endif()

if(NOT TARGET eUtil)
    add_subdirectory(${EUTIL_LIB_DIR})
endif()

if(NOT TARGET ${PROJECT_NAME})
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
    target_link_libraries(${PROJECT_NAME} PRIVATE eUtil)
    target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
    target_include_directories(${PROJECT_NAME} PUBLIC libBuild/hdr)
    target_include_directories(${PROJECT_NAME} PUBLIC thirdparty/eutil/libBuild/hdr)
    target_compile_definitions(${PROJECT_NAME} PRIVATE LOGCRAFT_EXPORTS)
endif()

message(STATUS "LogCraft build examples: " ${BUILD_EXAMPLES})
message(STATUS "LogCraft build tests: " ${BUILD_TESTING})

if(${BUILD_EXAMPLES})
    add_subdirectory(buildtest)
endif()

if(${BUILD_TESTING})
enable_testing()
    #add_subdirectory(tests)
endif()