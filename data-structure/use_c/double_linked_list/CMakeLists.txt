# cmake_minimum_required(VERSION <specify CMake version here>)
project(double_linked_list C)

set(CMAKE_C_STANDARD 99)

add_executable(double_linked_list main.c double_linked_list.c double_linked_list.h)