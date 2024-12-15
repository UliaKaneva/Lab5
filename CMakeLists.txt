cmake_minimum_required(VERSION 3.22)
project(Lab5)

set(CMAKE_CXX_STANDARD 20)


add_executable(task1 task1/main5-1.cpp
        task1/binary_int.cpp
        task1/binary_int.h)
add_executable(task2 task2/Encoder.cpp task2/Encoder.h
        task2/main5-2.cpp)
add_executable(task4 task4/Complex_Numbers.cpp task4/Complex_Numbers.h
        task4/main5-4.cpp)
add_executable(task3 task3/logical_values_array.cpp task3/logical_values_array.h
        task3/main5-3.cpp)
