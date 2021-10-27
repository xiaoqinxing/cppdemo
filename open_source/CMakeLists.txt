# 编译spd动态库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(spdlog)

# build release need threads lib
find_package(Threads)
set(RPCLIB_DEP_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_subdirectory(rpclib)

# gtest
add_subdirectory(googletest)

# opencv
set(BUILD_TESTS OFF)
set(BUILD_PERF_TESTS OFF)
add_subdirectory(opencv)