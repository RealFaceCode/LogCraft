cmake_minimum_required(VERSION 3.5)
project(buildtest VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS  "buildtest.cpp")
add_executable(buildtest ${SRC})
target_compile_features(buildtest PRIVATE cxx_std_23)
target_include_directories(buildtest PUBLIC libBuild/hdr)
target_link_libraries(buildtest PRIVATE LogCraft)
