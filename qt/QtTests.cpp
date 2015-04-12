
void qtTests() {}

#ifndef NO_QT_TEST_SUITE

// Qt vectors are implicitly shared
// and don't have rvalue constructor...
#define TTEST_SKIP_PROXY_MOVE_SEMANTICS

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "QVector", "[qvector]" )
{
    std::cout << "Running QVector tests." << std::endl;
    bool res = tt::fullRun<QVector,std::allocator>();
    REQUIRE( res );
}

#endif
