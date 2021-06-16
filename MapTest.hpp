#ifndef MAPTEST_HPP
#define MAPTEST_HPP

#include <sstream>
#include "Util.hpp"

#define MAP_TEST(FNC) ct.run("map::" #FNC, "STD", "FT ", \
                             map_test::FNC<STD>, map_test::FNC<FT>)

namespace map_test
{

/* constructor */
template <class map>
void constructor0(std::stringstream& out)
{
    typename ft::map::value_type make_pair;
    map m;

    if (m.insert(make_pair(4, 2)).second)
    {
        keyval(out, "success", true);
        pair<int,int> p = pair<int, int>(3, 4)
    }
}

}

#endif // MAPTEST_HPP
