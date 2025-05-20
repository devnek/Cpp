# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(VirtPersonExample VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(virtpers virtpers.cpp)
