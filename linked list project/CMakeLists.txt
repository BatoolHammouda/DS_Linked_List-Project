cmake_minimum_required(VERSION 3.22)
project(clion_projects C)

set(CMAKE_C_STANDARD 99)

add_executable(clion_projects main.c cmake-build-debug/linkedList.h)
