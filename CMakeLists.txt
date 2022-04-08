cmake_minimum_required(VERSION 3.21)
project(MyStandardAlgoLib)

set(CMAKE_CXX_STANDARD 17)
add_executable(MyStandardAlgoLib main.cpp include/sort.hpp include/forward_list.hpp include/hash_table.hpp include/deque.hpp)
