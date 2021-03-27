cmake_minimum_required(VERSION 3.17)
project(ReversePolishNotation C)

set(CMAKE_C_STANDARD 99)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(ReversePolishNotation main.c rpn.c rpn.h)

target_link_libraries(ReversePolishNotation libc_stack.a libqueue.a)