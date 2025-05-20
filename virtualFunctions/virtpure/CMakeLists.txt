# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(VirtPureExample VERSION 1.0)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create executable
add_executable(virtpure virtpure.cpp)
