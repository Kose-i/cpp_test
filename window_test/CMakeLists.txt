cmake_minimum_required(VERSION 2.8)
project(window_test)

find_package(GTK2 COMPONENTS gtk REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(ok_button WIN32 src/button.cpp)
target_link_libraries(ok_button GTK2::gtk)

add_executable(window_test WIN32 src/window.cpp)
target_link_libraries(window_test GTK2::gtk)

add_executable(window_test2 WIN32 src/window_2.cpp)
target_link_libraries(window_test2 GTK2::gtk)

#add_executable(ok_button WIN32 src/button.cpp)
#target_link_libraries(ok_button GTK2::gtk)

#add_executable(ok_button WIN32 src/button.cpp)
#target_link_libraries(ok_button GTK2::gtk)
