cmake_minimum_required(VERSION 3.17)
project(HTL-SWP_OP)

set(CMAKE_CXX_STANDARD 20)

add_executable(HTL-SWP_OP CPP/main.cpp CPP/measureStuff.h CPP/algo.h CPP/algo_sort.cpp CPP/algo_sort_count.cpp CPP/algo_search.cpp CPP/algo_search_count.cpp CPP/algo_misc.cpp CPP/test_def.h CPP/test_def.cpp)