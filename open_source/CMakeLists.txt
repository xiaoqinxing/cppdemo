# 编译spd动态库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(spdlog)

# build release need threads lib
find_package(Threads)
set(RPCLIB_DEP_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
add_subdirectory(rpclib)

# gtest
add_subdirectory(googletest)

execute_process(COMMAND source build_opencv.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})