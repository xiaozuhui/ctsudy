# cmake_minimum_required(VERSION <specify CMake version here>)
project(List C)

set(CMAKE_C_STANDARD 99)

add_executable(List main.c List.c List.h)