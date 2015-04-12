
#ifndef TESTDEFS_W9APLT0J
#define TESTDEFS_W9APLT0J

#define IFN_SECTOR_START(name) \
    int counter = 0;\
    const char* SECTOR_NAME = name;

#define IFN_RET_FALSE(expr) \
    if (!(expr)) {\
        std::cout << "FAILED AT: " << counter << std::endl;\
        std::cout << "SECTOR: |" << SECTOR_NAME << "|" << std::endl;\
        return false;\
    }\
    ++counter;

#include "testharness/CollectionAdapter.hpp"
#include "testharness/Proxies.hpp"
#include "testharness/VirtualCollection.hpp"
#include "testharness/CCountColTest.hpp"
#include "testharness/MoveTests.hpp"


#endif /* end of include guard: TESTDEFS_W9APLT0J */
