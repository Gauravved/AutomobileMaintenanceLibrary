cmake_minimum_required(VERSION 3.10)
project(VehicleMaintenance)

set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Main executable
add_executable(main src/main.cpp)

# GoogleTest setup for unit testing
enable_testing()

add_executable(runTests test/test.cpp)
add_test(NAME RunTests COMMAND runTests)
# target_include_directories(runTests PRIVATE include)
# target_link_libraries(runTests gtest gtest_main)

# include(GoogleTest)
# gtest_discover_tests(runTests)