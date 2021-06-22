#ifndef ITERATORRELATIONTEST_HPP
#define ITERATORRELATIONTEST_HPP

#include <sstream>
#include "Util.hpp"

#define ITER_REL(FNC) ct.run("map::" #FNC, "STD", "FT ", \
                             iter_rel_test::FNC<STD>, iter_rel_test::FNC<FT>)

namespace iter_rel_test
{

template <class Container>
void equal_const_nonConst(std::stringstream &out)
{
    Container       c;
    const Container cc;
    out << (c.begin() == cc.begin());
    out << (c.begin() != cc.begin());
}



}

#endif // ITERATORRELATIONTEST_HPP
