cmake_minimum_required(VERSION 3.15)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(sorting_algorithms src/main.cpp src/bubblesort/Bubblesort.cpp
        src/selectionsort/SelectionSort.cpp src/insertionsort/InsertionSort.cpp)
