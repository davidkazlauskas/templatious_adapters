/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main unit test ground
 *
 *        Version:  1.0
 *        Created:  07/27/2014 05:38:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David Kazlauskas (dk), david@templatious.org
 *
 * =====================================================================================
 */

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "TestDefs.hpp"

TEST_CASE("lol","[lol]")
{
    bool res = tt::fullRun<std::vector,std::allocator>();
    REQUIRE( res );
}

int main( int argc, char* const argv[] )
{
    int result = Catch::Session().run( argc, argv );
    return result;
}

