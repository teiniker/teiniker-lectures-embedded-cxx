cmake_minimum_required(VERSION 3.25)

project(data-service LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable compiler warnings globally, activate debugging, and check for gtest
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
find_package(GTest REQUIRED)

include_directories(./)
add_executable(test test.cpp file_service.cpp data_service.cpp)

# Absolute path to the test data, independent of the working directory
target_compile_definitions(test PRIVATE
    DATA_FILE="${CMAKE_CURRENT_SOURCE_DIR}/data.txt")

target_link_libraries(test PRIVATE gtest gtest_main pthread)
