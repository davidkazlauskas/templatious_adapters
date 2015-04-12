
void qtTests() {}

#ifndef NO_QT_TEST_SUITE

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "QVector", "[qvector]" )
{
    std::cout << "Running QVector tests." << std::endl;
    bool res = tt::intRun<QVector,std::allocator>();
    REQUIRE( res );
}

#endif
