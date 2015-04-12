
cmake_minimum_required(VERSION 2.6)

project(TTEST CXX)

function(assert_defined variable)
    if(NOT DEFINED ENV{${variable}})
        message(FATAL_ERROR "${variable} is undefined in enviroment.")
    endif(NOT DEFINED ENV{${variable}})
endfunction(undeferr)

assert_defined( TEMPLATIOUS_DIR )

SET( TEMPLATIOUS_DIR
    $ENV{TEMPLATIOUS_DIR} )

include_directories( ${UPP_INCLUDE_DIR} ${TEMPLATIOUS_DIR} )

ADD_DEFINITIONS(
    -std=c++11
    -Wall
    -x c++
    -ggdb3
    -O0
)

SET(CMAKE_CXX_COMPILER "g++-4.9")

add_subdirectory( ultimatepp )

add_executable( a.out main.cpp )
target_link_libraries( a.out UltimateppTests )

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

