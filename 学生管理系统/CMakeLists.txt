cmake_minimum_required(VERSION 3.16)
project(demo1 C)

set(CMAKE_C_STANDARD 99)

link_directories(lib)

add_executable(demo1 main.c srcs/Students.c headers/Students.h srcs/Tools.c headers/Tools.h headers/DBTools.h srcs/DBTools.c)

target_link_libraries(demo1 sqlite3)