
void uppBiVectorTest() {}

#ifndef NO_UPP_TEST_SUITE

#define TTEST_SKIP_UPP_BIVECTOR // is it worth it? I don't think so

#ifndef TTEST_SKIP_UPP_BIVECTOR

// requires wrapping type in some
// nonsense to be contained in the vector
#define TTEST_SKIP_MISC_MOVE_TEST
#define TTEST_SKIP_DESTRUCTOR_COUNT

// no insertion for bivector
#define TTEST_SKIP_INSERT
#define TTEST_SKIP_ERASE

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "Upp::BiVector", "[upp_bivector]" )
{
    std::cout << "Running Upp::BiVector tests." << std::endl;
    bool res = tt::fullRun<Upp::BiVector,std::allocator>();
    REQUIRE( res );
}

#endif

#endif
