cmake_minimum_required(VERSION 3.21)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures main.cpp cmake-build-debug/Queue.cpp cmake-build-debug/Queue.h)
