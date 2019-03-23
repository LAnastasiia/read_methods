cmake_minimum_required(VERSION 3.5.1)
project(cheker)

set(CMAKE_CXX_STANDARD 14)

add_executable(cheker main.cpp functions/read_methods.h functions/time_measure.h)