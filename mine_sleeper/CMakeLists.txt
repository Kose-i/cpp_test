cmake_minimum_required(VERSION 3.0)

project(mine_sleeper)
add_definitions("-std=c++14")
include_directories(include)

add_executable(main src/main.cpp src/mine_sleeper.cpp)
