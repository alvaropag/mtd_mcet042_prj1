cmake_minimum_required(VERSION 4.1)
project(prj1 C)

set(CMAKE_C_STANDARD 90)

add_executable(prj1 main.c
        file_reader.c
        simple_list.h
        simple_list.c
        file_reader.h
        list_node.h)
