
void uppTests() {}

#ifndef NO_UPP_TEST_SUITE

// requires wrapping type in some
// nonsense to be contained in the vector
#define TTEST_SKIP_MISC_MOVE_TEST
#define TTEST_SKIP_DESTRUCTOR_COUNT

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
