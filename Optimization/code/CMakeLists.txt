cmake_minimum_required(VERSION 3.10)
project(LoopUnrollingExample)

set(CMAKE_CXX_STANDARD 11)
# Disable optimizations by setting the optimization level to 0
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(loop_unrolling_example loopUnrolling.cpp)