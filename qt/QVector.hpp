#ifndef QVECTOR_ROGE1AIY
#define QVECTOR_ROGE1AIY

#include <utility>
#include <QVector>

#include <templatious/util/Selectors.hpp>
#include <templatious/CollectionMaker.hpp>
#include <templatious/CollectionAdapter.hpp>

namespace templatious {
namespace adapters {

template <class T>
struct CollectionAdapter< QVector<T> > {

    static const bool is_valid = true;
    static const bool floating_iterator = true;

	typedef QVector<T> ThisCol;
	typedef QVector<T> const ConstCol;
	typedef typename ThisCol::Iterator Iterator;
	typedef typename ThisCol::ConstIterator ConstIterator;
	typedef T ValueType;
	typedef const T ConstValueType;

    template <class V>
	static void add(ThisCol& c,V&& i) {
		c.push_back(std::forward<V>(i));
	}

    template <class V>
    static void insertAt(ThisCol& c, Iterator at, V&& v) {
        if (at < begin(c) || at >= end(c)) {
            throw CollectionAdapterIteratorOutOfBoundsException();
        }

        c.insert(at,std::forward<V>(v));
    }

	static Iterator begin(ThisCol& c) {
		return c.begin();
	}

	static Iterator end(ThisCol& c) {
		return c.end();
	}

    static Iterator iterAt(ThisCol& c,long pos) {
        if (c.size() < pos || pos < 0) {
            throw CollectionAdapterNoSuchIteratorException();
        }
        return c.begin() + pos;
    }

    static ConstIterator iterAt(ConstCol& c,long pos) {
        if (c.size() < pos || pos < 0) {
            throw CollectionAdapterNoSuchIteratorException();
        }
        return c.constBegin() + pos;
    }

    static ConstIterator citerAt(ConstCol& c,long pos) {
        if (c.size() < pos || pos < 0) {
            throw CollectionAdapterNoSuchIteratorException();
        }
        return c.constBegin() + pos;
    }

	static ConstIterator begin(ConstCol& c) {
		return c.constBegin();
	}

	static ConstIterator end(ConstCol& c) {
		return c.constEnd();
	}

	static ConstIterator cbegin(ConstCol& c) {
		return c.constBegin();
	}

	static ConstIterator cend(ConstCol& c) {
		return c.constEnd();
	}

	static long size(ConstCol& c) {
		return c.size();
	}

    static ValueType& getByIndex(ThisCol& c, long i) {
        return c[i];
    }

    static ConstValueType& getByIndex(ConstCol& c, long i) {
        return c[i];
    }

    static void erase(ThisCol& c,Iterator pos) {
        c.erase(pos);
    }

    static void erase(ThisCol& c,Iterator beg,Iterator end) {
        c.erase(beg,end);
    }

    static ValueType& first(ThisCol& c) {
        return c.front();
    }

    static ConstValueType& first(ConstCol& c) {
        return c.front();
    }

    static ValueType& last(ThisCol& c) {
        return c.back();
    }

    static ConstValueType& last(ConstCol& c) {
        return c.back();
    }

    static void clear(ThisCol& c) {
        c.clear();
    }

    static bool canAdd(ConstCol& c) {
        return true;
    }

};

template <class T>
struct CollectionAdapter< const QVector<T> > {

    static const bool is_valid = true;
    static const bool floating_iterator = true;

	typedef QVector<T> const ThisCol;
	typedef QVector<T> const ConstCol;
	typedef typename ThisCol::ConstIterator Iterator;
	typedef typename ThisCol::ConstIterator ConstIterator;
	typedef const T ValueType;
	typedef const T ConstValueType;

    template <class V,class U = int>
	static void add(ThisCol& c,V&& i) {
        static_assert(templatious::util::DummyResolver<U,false>::val,
                "Const version of a collection doesn't support this method");
	}

    template <class V,class U = int>
    static void insertAt(ThisCol& c, Iterator at, V&& v) {
        static_assert(templatious::util::DummyResolver<U,false>::val,
                "Const version of a collection doesn't support this method");
    }

	static ConstIterator begin(ConstCol& c) {
		return c.constBegin();
	}

	static ConstIterator end(ConstCol& c) {
		return c.constEnd();
	}

	static ConstIterator cbegin(ConstCol& c) {
		return c.constBegin();
	}

	static ConstIterator cend(ConstCol& c) {
		return c.constEnd();
	}

	static long size(ConstCol& c) {
		return c.size();
	}

    static ValueType& getByIndex(ThisCol& c, long i) {
        return c[i];
    }

    static Iterator iterAt(ConstCol& c,long pos) {
        if (c.size() < pos || pos < 0) {
            throw CollectionAdapterNoSuchIteratorException();
        }
        return c.constBegin() + pos;
    }

    static Iterator citerAt(ConstCol& c,long pos) {
        if (c.size() < pos || pos < 0) {
            throw CollectionAdapterNoSuchIteratorException();
        }
        return c.constBegin() + pos;
    }

    template <class U = int>
    static void erase(ThisCol& c,Iterator pos) {
        static_assert(templatious::util::DummyResolver<U,false>::val,
                "Const version of a collection doesn't support this method");
    }

    template <class U = int>
    static void erase(ThisCol& c,Iterator beg,Iterator end) {
        static_assert(templatious::util::DummyResolver<U,false>::val,
                "Const version of a collection doesn't support this method");
    }

    static ConstValueType& first(ConstCol& c) {
        return c.front();
    }

    static ConstValueType& last(ConstCol& c) {
        return c.back();
    }

    template <class U = int>
    static void clear(ThisCol& c) {
        static_assert(templatious::util::DummyResolver<U,false>::val,
                "Const version of a collection doesn't support this method");
    }

    static bool canAdd(ThisCol& c) {
        return false;
    }

};


template <
    class Val,
    template <class> class Alloc
>
struct CollectionMaker<Val,QVector,Alloc> {
    typedef QVector<Val> Collection;
    typedef Collection* CollectionPtr;

    static const bool is_maker_valid = true;

    static Collection make() {
        return std::move(Collection());
    }

    static Collection make(long size) {
        Collection res;
        res.reserve(size);
        return std::move(res);
    }

    static Collection* makeHeap() {
        return new Collection();
    }

    static Collection* makeHeap(long size) {
        CollectionPtr res = new Collection();
        res->reserve(size);
        return res;
    }

};

}
}

#endif /* end of include guard: QVECTOR_ROGE1AIY */

