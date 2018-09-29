cmake_minimum_required(VERSION 2.8.3)
project(time
)

include_directories(include)

add_executable(main src/main.cpp src/time_alarm.cpp)
