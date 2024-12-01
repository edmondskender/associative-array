cmake_minimum_required(VERSION 3.29)
project(associative_array)

set(CMAKE_CXX_STANDARD 20)

add_executable(associative_array main.cpp
        dynamic_array.h
        pair.h
        associative_array.h)
