cmake_minimum_required(VERSION 3.16.3)
project(queue C)

set(CMAKE_C_STANDARD 99)

#add_library(queue Queue.c Queue.h)
add_executable(queue main.c Queue.c Queue.h CircleQueue.c CircleQueue.h DoubleQueue.c DoubleQueue.h)
