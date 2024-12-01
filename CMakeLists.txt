cmake_minimum_required(VERSION 3.22)
project(Lab5)

set(CMAKE_CXX_STANDARD 20)


add_executable(task1 task1/main5-1.cpp
        task1/binary_int.cpp
        task1/binary_int.h)
add_executable(task2 task2/encoder.cpp task2/encoder.h)
