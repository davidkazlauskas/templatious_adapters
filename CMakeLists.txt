
cmake_minimum_required(VERSION 2.6)

project(TTEST CXX)

#SET( UPP_INCLUDE_DIR
    #"/usr/share/upp/uppsrc/" )
## path to Core.a/Core.lib here
#SET( UPP_LIB
    #"/home/deividas/Desktop/storage/Prj/upp/out/bazaar/Core/GCC4.Debug.Debug_Full.Noblitz.Shared.Sse2/Core.a")

SET( TEMPLATIOUS_DIR
    "/home/deividas/Desktop/Dropbox/MyPrj/Templatious" )

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

