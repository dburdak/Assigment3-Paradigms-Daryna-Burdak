cmake_minimum_required(VERSION 3.31)
project(assigment3_exe)

set(CMAKE_CXX_STANDARD 98)
include_directories(/Users/darynaburdak/CLionProjects/ass3_static)
add_executable(assigment3_exe main.cpp)
target_link_libraries(assigment3_exe /Users/darynaburdak/CLionProjects/ass3_static/libass3_static.a)