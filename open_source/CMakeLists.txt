cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/../prebuilts/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/../prebuilts/lib)
set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/prebuilts)
# 编译spd动态库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(spdlog)

# build release need threads lib
find_package(Threads)
set(RPCLIB_DEP_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_subdirectory(rpclib)

# gtest
add_subdirectory(googletest)