
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

namespace tt = test_templatious;

#include "testharness/CollectionAdapter.hpp"
#include "testharness/Proxies.hpp"
#include "testharness/VirtualCollection.hpp"
#include "testharness/CCountColTest.hpp"
#include "testharness/MoveTests.hpp"

namespace test_templatious {

template <
    template <class...> class Collection,
    template <class> class Allocator
>
bool intRun() {
    IFN_SECTOR_START("FULL RUN");

    typedef templatious::adapters::
        CollectionMaker<int,Collection,Allocator> Maker;

    auto col = Maker::make();

    IFN_RET_FALSE(tt::existantCollectionTest(col));
    IFN_RET_FALSE(tt::proxyTest(col));
    IFN_RET_FALSE(tt::constProxyTest(col));
    IFN_RET_FALSE(tt::proxyDeletionTest(col));
    IFN_RET_FALSE(tt::virtualTest(col));

    return true;
}

template <
    template <class...> class Collection,
    template <class> class Allocator
>
bool fullRun() {
    IFN_SECTOR_START("FULL RUN");

    IFN_RET_FALSE(intRun<Collection,Allocator>());

    return true;
}

}

#endif /* end of include guard: TESTDEFS_W9APLT0J */
