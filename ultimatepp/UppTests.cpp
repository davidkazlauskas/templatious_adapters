
void uppTests() {}

#ifndef NO_UPP_TEST_SUITE

#include "../catch.hpp"
#include "../TestDefs.hpp"
#include "All.hpp"

TEST_CASE( "Upp::Vector", "[upp_vector]" )
{
    std::cout << "Running Upp::Vector tests." << std::endl;
    bool res = tt::intRun<Upp::Vector,std::allocator>();
    REQUIRE( res );
}

#endif
