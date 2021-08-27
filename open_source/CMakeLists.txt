# 编译spd动态库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(spdlog)

add_subdirectory(rpclib)
add_subdirectory(googletest)