cmake_minimum_required(VERSION 2.8.3)

project(mouse_on_ubuntu
#  LANGUAGES CXX
#  VERSION 0.0.0
)

include_directories(include)

add_executable(main src/mouse_set.cpp src/main.cpp)
