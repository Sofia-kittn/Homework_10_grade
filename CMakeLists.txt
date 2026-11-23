cmake_minimum_required(VERSION 3.30)
project(homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework main.cpp
        code.cpp
        stack.cpp
        BST.cpp
        heap.cpp
        segment_tree.cpp)
