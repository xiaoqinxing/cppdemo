cmake_minimum_required(VERSION 3.10)
project(test_condition_variable CXX)

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_executable(test_condition_variable test_condition_variable.cpp)
target_link_libraries(test_condition_variable PRIVATE gtest_main)