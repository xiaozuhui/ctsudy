cmake_minimum_required(VERSION 3.16)
project(cds C)

set(CMAKE_C_STANDARD 99)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_executable(cds main.c Stack.h)

target_link_libraries(cds libc_stack.a)