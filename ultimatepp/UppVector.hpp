
#ifndef UPPVECTOR_ST0TPQEU
#define UPPVECTOR_ST0TPQEU

#include <Core/Core.h>

namespace templatious {
namespace adapters {

template <class T>
struct CollectionAdapter< Upp::Vector<T> > {

    static const bool is_valid = true;
    static const bool floating_iterator = true;

	typedef typename Upp::Vector<T> ThisCol;
	typedef typename Upp::Vector<T> const ConstCol;
	typedef typename ThisCol::Iterator Iterator;
	typedef typename ThisCol::ConstIterator ConstIterator;
	typedef T ValueType;
	typedef const T ConstValueType;

    template <class V>
	static void add(ThisCol& c,V&& i) {
		c.Add(std::forward<V>(i));
	}

    template <class V>
    static void insertAt(ThisCol& c,Iterator at, V&& v) {
        c.Insert(iterDiff(begin(c),at));
    }

	static Iterator begin(ThisCol& c) {
		return c.Begin();
	}

	static Iterator end(ThisCol& c) {
		return c.End();
	}

    static Iterator iterAt(ThisCol& c,size_t pos) {
        return c.GetIter(pos);
    }

    static ConstIterator iterAt(ConstCol& c,size_t pos) {
        return c.GetIter(pos);
    }

    static ConstIterator citerAt(ConstCol& c,size_t pos) {
        return c.GetIter(pos);
    }

	static ConstIterator begin(ConstCol& c) {
		return c.Begin();
	}

	static ConstIterator end(ConstCol& c) {
		return c.End();
	}

	static ConstIterator cbegin(ConstCol& c) {
		return c.Begin();
	}

	static ConstIterator cend(ConstCol& c) {
		return c.End();
	}

	static long size(ConstCol& c) {
		return c.GetCount();
	}

    static ValueType& getByIndex(ThisCol& c, size_t i) {
        return c.Get(i);
    }

    static ConstValueType& getByIndex(ConstCol& c, size_t i) {
        return c.Get(i);
    }

    static void erase(ThisCol& c,Iterator pos) {
        c.Remove(iterDiff(begin(c)),pos,1);
    }

    static void erase(ThisCol& c,Iterator beg,Iterator end) {
        c.Remove(iterDiff(begin(c)),pos,iterDiff(beg,end));
    }

    static ValueType& first(ThisCol& c) {
        return *begin(c);
    }

    static ConstValueType& first(ConstCol& c) {
        return *cbegin(c);
    }

    static ValueType& last(ThisCol& c) {
        return c.Top();
    }

    static ConstValueType& last(ConstCol& c) {
        return c.Top();
    }

    static void clear(ThisCol& c) {
        c.Clear();
    }

    static bool canAdd(ConstCol& c) {
        return true;
    }

private:
    template <class ThisIter>
    static int iterDiff(const ThisIter& a,const ThisIter& b) {
        return b - a;
    }
};

template <class T>
struct CollectionAdapter< const Upp::Vector<T> > {

    static const bool is_valid = true;
    static const bool floating_iterator = true;

	typedef typename Upp::Vector<T> const ThisCol;
	typedef typename Upp::Vector<T> const ConstCol;
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
		return c.Begin();
	}

	static ConstIterator end(ConstCol& c) {
		return c.End();
	}

	static ConstIterator cbegin(ConstCol& c) {
		return c.Begin();
	}

	static ConstIterator cend(ConstCol& c) {
		return c.End();
	}

	static long size(ConstCol& c) {
		return c.Count();
	}

    static ValueType& getByIndex(ThisCol& c, size_t i) {
        return c.Get(i);
    }

    static Iterator iterAt(ConstCol& c,size_t pos) {
        return c.GetIter(pos);
    }

    static Iterator citerAt(ConstCol& c,size_t pos) {
        return c.GetIter(pos);
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
        return *begin(c);
    }

    static ConstValueType& last(ConstCol& c) {
        return c.Top();
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
struct CollectionMaker<Val,Upp::Vector,Alloc> {
    typedef Upp::Vector<Val,Alloc<Val> > Collection;
    typedef Collection* CollectionPtr;

    static const bool is_maker_valid = true;

    static Collection make() {
        return std::move(Collection());
    }

    static Collection make(size_t size) {
        Collection res;
        res.reserve(size);
        return std::move(res);
    }

    static Collection* makeHeap() {
        return new Collection();
    }

    static Collection* makeHeap(size_t size) {
        CollectionPtr res = new Collection();
        res->reserve(size);
        return res;
    }

};

}
}

#endif /* end of include guard: UPPVECTOR_ST0TPQEU */
