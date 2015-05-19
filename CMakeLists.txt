
cmake_minimum_required(VERSION 2.6)

project(TTEST CXX)

function(assert_defined variable)
    if(NOT DEFINED ENV{${variable}})
        message(FATAL_ERROR "${variable} is undefined in enviroment.")
    endif(NOT DEFINED ENV{${variable}})
endfunction(assert_defined)

assert_defined( TEMPLATIOUS_DIR )

SET( TEMPLATIOUS_DIR
    $ENV{TEMPLATIOUS_DIR} )

ADD_DEFINITIONS(
    -std=c++11
    -Wall
    -x c++
)

add_subdirectory( ultimatepp )
add_subdirectory( qt )

SET( TEST_LIBS
    UltimateppTests
    QtTests
)

add_executable( a.out main.cpp )
target_link_libraries( a.out ${TEST_LIBS} )

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

