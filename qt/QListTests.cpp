
void qList() {}

#ifndef NO_QT_TEST_SUITE

// Qt lists are implicitly shared
// and don't have rvalue constructor...
#define TTEST_SKIP_PROXY_MOVE_SEMANTICS

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "QList", "[qlist]" )
{
    std::cout << "Running QList tests." << std::endl;
    bool res = tt::fullRun<QList,std::allocator>();
    REQUIRE( res );
}

#endif
