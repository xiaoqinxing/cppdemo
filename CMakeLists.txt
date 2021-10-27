cmake_minimum_required(VERSION 3.10)

message(STATUS "HOME_DIRECTORY: ${CMAKE_HOME_DIRECTORY}")

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb -fsanitize=address -fno-omit-frame-pointer -static-libasan")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/out/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/out/lib)
set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)

add_subdirectory(open_source)
add_subdirectory(src)
add_subdirectory(tests)