cmake_minimum_required(VERSION 3.25)
project(SkipList)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(test main.cpp)
