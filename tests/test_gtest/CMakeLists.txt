cmake_minimum_required(VERSION 3.10)
project(test_gtest CXX)

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(test_gtest test_gtest.cpp)
target_link_libraries(test_gtest PRIVATE gtest_main)