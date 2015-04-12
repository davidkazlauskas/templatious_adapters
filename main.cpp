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

void uppTests();

// tests are not always run
// in the library, so, we execute
// some dummy functions from libraries
// to make sure catch framework
// registers tests and they would
// be run
void useSymbols() {
    uppTests();
}

int main( int argc, char* const argv[] )
{
    useSymbols();

    int result = Catch::Session().run( argc, argv );
    return result;
}

