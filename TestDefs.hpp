
#ifndef TESTDEFS_W9APLT0J
#define TESTDEFS_W9APLT0J

#include <iostream>

#define TEMPLATIOUS_TESTING

#include <templatious/FullPack.hpp>

TEMPLATIOUS_TRIPLET_STD;

#define DEF_ADAPTER(cl,name) typedef templatious::adapters::CollectionAdapter<cl> name

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

namespace test_templatious {
    namespace t = templatious;
    namespace tt = test_templatious;
}

namespace tt = test_templatious;

#include "testharness/CollectionAdapter.hpp"
#include "testharness/Proxies.hpp"
#include "testharness/VirtualCollection.hpp"
#include "testharness/ConstructorCountCollection.hpp"
#include "testharness/CCountColTest.hpp"
#include "testharness/MoveTests.hpp"

namespace test_templatious {

template <
    template <class...> class Collection,
    template <class> class Allocator =
        std::allocator
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
    template <class> class Allocator =
        std::allocator
>
bool moveCountRun() {
    IFN_SECTOR_START("MOVE RUN");

    { // DESTRUCTOR COUNT
        struct UniqueToken {};
        typedef tt::ConstructorCountCollection<UniqueToken> ValType;

        typedef templatious::adapters::
            CollectionMaker<ValType,Collection,Allocator> Maker;
        auto v = Maker::make();

        IFN_RET_FALSE(tt::constructionCountCollectionTest<UniqueToken>(v));
        IFN_RET_FALSE(ValType::count() == 0);
    }

    { // MOVE TEST
        typedef templatious::adapters::
            CollectionMaker<MovablePod,Collection,Allocator> Maker;
        auto v = Maker::make();
    }

    return true;
}

template <
    template <class...> class Collection,
    template <class> class Allocator =
        std::allocator
>
bool fullRun() {
    IFN_SECTOR_START("FULL RUN");

    bool expr = intRun<Collection,Allocator>();
    IFN_RET_FALSE(expr);

    expr &= moveCountRun<Collection,Allocator>();
    IFN_RET_FALSE(expr);

    return true;
}

}

#endif /* end of include guard: TESTDEFS_W9APLT0J */
