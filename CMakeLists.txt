
cmake_minimum_required(VERSION 2.6)

project(TTEST CXX)

include_directories("/home/deividas/Desktop/Dropbox/MyPrj/Templatious")

ADD_DEFINITIONS(
    -std=c++11
    -Wall
    -x c++
    -ggdb3
    -O0
)

SET(CMAKE_CXX_COMPILER "g++-4.9")

add_executable(a.out main.cpp)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

