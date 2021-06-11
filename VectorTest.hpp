#ifndef VECTORTEST_HPP
#define VECTORTEST_HPP

#include <sstream>
#include "Util.hpp"

#define VECTOR_TEST(FNC) ct.run("list::" #FNC, "STD", "FT ", \
                                vector_test::FNC<STD>, vector_test::FNC<FT>)

namespace vector_test
{

template <class vector>
void info(std::stringstream& out, const vector& v)
{
    keyval(out, "size", v.size());
    keyval(out, "capacity", v.capacity());
    printIter(out, v);
}

/* constructor */
template <class vector>
void constructor0(std::stringstream& out)
{
    vector v;

    info(out, v);

    v.push_back(42);
    info(out, v);
}

template <class vector>
void constructor1(std::stringstream& out)
{
    vector v(2);
    info(out, v);

    vector v2(3, 42);
    info(out, v2);
}

}

#endif // VECTORTEST_HPP
