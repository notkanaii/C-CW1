cmake_minimum_required(VERSION 3.17)
project(library C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(library
        book_management.h
        interface.c
        library.c
        user.c
        users.h cmake-build-debug/main.c)
