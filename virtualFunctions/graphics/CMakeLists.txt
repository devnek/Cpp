# Minimum required version
cmake_minimum_required(VERSION 3.10)

# Project name
project(VirtShapeExample VERSION 1.0)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(virtshap virtshap.cpp msoftcon.cpp)

# If using Windows with WinBGIm or Console Graphics, you may need to link additional libraries:
# target_link_libraries(virtshap gdi32)  # Windows only, if needed
