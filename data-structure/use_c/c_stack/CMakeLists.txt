cmake_minimum_required(VERSION 3.16)
project(c_stack C)

set(CMAKE_C_STANDARD 99)

add_library(c_stack Stack.c Stack.h)