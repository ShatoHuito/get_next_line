cmake_minimum_required(VERSION 3.17)
project(My_GNL C)

set(CMAKE_C_STANDARD 99)

add_definitions(-DBUFFER_SIZE=16)

add_definitions(-Wall -Wextra -Werror)

add_executable(My_GNL main.c get_next_line.c get_next_line_utils.c get_next_line.h)