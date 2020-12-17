CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(categorizer LANGUAGES CXX)

FILE(GLOB sources "src/*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(categorizer ${sources})

target_include_directories(categorizer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

