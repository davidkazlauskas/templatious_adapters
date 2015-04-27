
void uppVectorTest() {}

#ifndef NO_UPP_TEST_SUITE

// requires wrapping type in some
// nonsense to be contained in the vector
#define TTEST_SKIP_MISC_MOVE_TEST
#define TTEST_SKIP_DESTRUCTOR_COUNT

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "Upp::Vector", "[upp_vector]" )
{
    std::cout << "Running Upp::Vector tests." << std::endl;
    bool res = tt::fullRun<Upp::Vector,std::allocator>();
    REQUIRE( res );
}

#endif
