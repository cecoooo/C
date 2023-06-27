cmake_minimum_required(VERSION 3.21)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures main.cpp cmake-build-debug/Queue.cpp cmake-build-debug/Queue.h cmake-build-debug/Stack.cpp cmake-build-debug/Stack.h cmake-build-debug/LinkedList.cpp cmake-build-debug/LinkedList.h)
