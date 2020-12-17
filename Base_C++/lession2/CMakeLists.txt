CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(program)

add_executable(program src/05_Tasks.cpp)

target_include_directories(program PRIVATE include)
