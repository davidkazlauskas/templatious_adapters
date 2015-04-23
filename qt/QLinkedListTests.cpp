
void qLinkedList() {}

#ifndef NO_QT_TEST_SUITE

// Qt containers are implicitly shared
// and don't have rvalue constructor...
#define TTEST_SKIP_PROXY_MOVE_SEMANTICS

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "QLinkedList", "[qlist]" )
{
    std::cout << "Running QLinkedList tests." << std::endl;
    bool res = tt::fullRun<QLinkedList,std::allocator>();
    REQUIRE( res );
}

#endif
