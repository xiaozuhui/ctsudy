cmake_minimum_required(VERSION 3.19)
project(c_stack C)

set(CMAKE_C_STANDARD 99)

add_executable(c_stack main.c stack.c stack.h rpn.c rpn.h utils.c utils.h)
