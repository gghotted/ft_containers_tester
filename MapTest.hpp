#ifndef MAPTEST_HPP
#define MAPTEST_HPP

#include <sstream>
#include "Util.hpp"
#include "vector.hpp"

#define MAP_TEST(FNC) ct.run("map::" #FNC, "STD", "FT ", \
                             map_test::FNC<STD>, map_test::FNC<FT>)

namespace map_test
{

template <class pair>
void printPair(std::stringstream& out, const pair& pair_)
{
    out << "[" << pair_.first << ":" << pair_.second << "] ";
}

template <class iterator>
void printIterMap(std::stringstream& out, iterator it, iterator ite)
{
    for (; it != ite; ++it)
        printPair(out, *it);
}

template <class map>
void info(std::stringstream& out, const map& m)
{
    keyval(out, "size", m.size());
    printIterMap(out, m.begin(), m.end());
}

/* constructor */
template <class map>
void constructor0(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 3));
    info(out, m);
}

template <class map>
void constructor1(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 3));

    map m2(m.begin(), m.end());
    info(out, m2);
}

template <class map>
void copyConstructor(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 3));

    map m2(m);
    info(out, m2);
}

template <class map>
void assignation(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 3));

    map m2;
    m.insert(make_pair(3, 3));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m2 = m;
    info(out, m2);
}

/* iterator */
template <class map>
void begin_end(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(3, 3));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));
    info(out, m);

    const map cm(m);
    info(out, cm);
}

template <class map>
void rbegin_rend(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(3, 3));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));
    printIterMap(out, m.rbegin(), m.rend());

    const map cm(m);
    printIterMap(out, cm.rbegin(), cm.rend());
}

/* capacity */
template <class map>
void empty(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    keyval(out, "empty", m.empty());
    m.insert(make_pair(3, 3));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));
    keyval(out, "empty", m.empty());
}

template <class map>
void size(std::stringstream &out)
{
    typedef typename map::value_type make_pair;

    map m;
    keyval(out, "size", m.size());

    m.insert(make_pair(1, 1));
    keyval(out, "size", m.size());

    m.clear();
    keyval(out, "size", m.size());
}

template <class map>
void max_size(std::stringstream &out)
{
    map m;
    out << CompareTester::DontNeedToSame << "-> ";
    keyval(out, "max_size", m.max_size());
}

/* element access */
template <class map>
void accessOperator(std::stringstream &out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(3, 3));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));
    for (int i = 6; i <= 10; i++)
        m[i] = i;
    for (int i = 1; i <= 10; i++)
        out << m[i] << " ";
}

/* modifiers */
template <class map>
void insert0(std::stringstream &out)
{
    typedef typename map::value_type make_pair;

    map m;
    for (size_t i = 0; i < 10; i++)
        m.insert(make_pair(range[i], range[i]));
    info(out, m);
}

/*
1
 2
  3
   4
    5
*/
template <class map>
void erase0(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(1, 1));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(3, 3));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));

    m.erase(m.begin());
    m.erase(++m.begin());
    m.erase(--m.end());
    info(out, m);
}

/*
  3
 2 4
1   5
*/
// template <class map>
// void erase1(std::stringstream& out)
// {
//     typedef typename map::value_type make_pair;

//     map m;
//     m.insert(make_pair(3, 3));
//     m.insert(make_pair(2, 2));
//     m.insert(make_pair(1, 1));
//     m.insert(make_pair(4, 4));
//     m.insert(make_pair(5, 5));

//     m.erase(m.begin());
//     m.erase(++m.begin());
//     m.erase(--m.end());
//     info(out, m);
// }

/* operations */
template <class map>
void find(std::stringstream& out)
{
    typedef typename map::value_type make_pair;

    map m;
    m.insert(make_pair(3, 3));
    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 1));
    m.insert(make_pair(4, 4));
    m.insert(make_pair(5, 5));

    for (int i = 1; i <= 5; i++)
        printPair(out, *m.find(i));
    keyval(out, "is_end", m.find(6) == m.end());
}

// template <class T>
// struct greater{
//     bool operator() (const T& x, const T& y) const {return x>y;}
// };

// template <class map>
// void constructor_with_comp(std::stringstream& out)
// {
//     typedef typename map::value_type make_pair;

//     map m(greater<typename map::key_type>);
//     m.insert(make_pair(1, 1));
//     m.insert(make_pair(2, 2));
//     m.insert(make_pair(3, 3));

//     map m2(m.begin(), m.end());
//     info(out, m2);
// }

}

#endif // MAPTEST_HPP