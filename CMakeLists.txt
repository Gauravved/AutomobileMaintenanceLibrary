cmake_minimum_required(VERSION 3.10)

# Project name and version
project(AUTOMOBILEMAINTENANCELIBRARY VERSION 1.0)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(automobile_maintenance main.cpp)
