cmake_minimum_required(VERSION 3.16)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkedList main.c linked_list.c linked_list.h)