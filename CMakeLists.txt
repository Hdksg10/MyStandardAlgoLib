cmake_minimum_required(VERSION 3.21)
project(MyStandardAlgoLib)

set(CMAKE_CXX_STANDARD 17)
add_executable(MyStandardAlgoLib main.cpp include/sort.hpp include/forward_list.hpp include/hash_table.hpp include/deque.hpp include/list.hpp include/base.hpp include/array.hpp include/binary_search_tree.h src/binary_search_tree.cpp include/rb_tree.h src/rb_tree.cpp)
