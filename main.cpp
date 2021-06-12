/* containers */
#include "list.hpp"
#include "vector.hpp"
/* containers */

#include "CompareTester.hpp"
#include "ListTest.hpp"
#include "VectorTest.hpp"

#include <iostream>
#include <list>
#include <vector>

void testList(CompareTester& ct)
{
    typedef std::list<int>  STD;
    typedef ft::list<int>   FT;

    /* constructor */
    LIST_TEST(constructor0);
    LIST_TEST(constructor1);
    LIST_TEST(constructor2);
    LIST_TEST(copyConstructor);

    /* operator */
    LIST_TEST(assignation);

    /* iterator */
    LIST_TEST(begin_end);
    LIST_TEST(rbegin_rend);

    /* capacity */
    LIST_TEST(empty);
    LIST_TEST(max_size);

    /* modifiers */
    LIST_TEST(assign0);
    LIST_TEST(assign1);
    LIST_TEST(push_front);
    LIST_TEST(pop_front);
    LIST_TEST(push_back);
    LIST_TEST(pop_back);
    LIST_TEST(insert0);
    LIST_TEST(insert1);
    LIST_TEST(insert2);
    LIST_TEST(erase0);
    LIST_TEST(erase1);
    LIST_TEST(swap);
    LIST_TEST(resize);
    LIST_TEST(clear);

    /* operations */
    LIST_TEST(splice0);
    LIST_TEST(splice1);
    LIST_TEST(splice2);
    LIST_TEST(remove);
    LIST_TEST(remove_if);
    LIST_TEST(unique0);
    LIST_TEST(unique1);
    LIST_TEST(merge0);
    LIST_TEST(reverse);
    LIST_TEST(sort0);
    LIST_TEST(sort1);

    LIST_TEST(relationOperation);
}

void testListDouble(CompareTester& ct)
{
    typedef std::list<double>  STD;
    typedef ft::list<double>   FT;

    LIST_TEST(merge1);
}

void testVector(CompareTester& ct)
{
    typedef std::vector<int>  STD;
    typedef ft::vector<int>   FT;

    /* constructor */
    VECTOR_TEST(constructor0);
    VECTOR_TEST(constructor1);
    VECTOR_TEST(constructor2);
    VECTOR_TEST(copyConstructor);

    /* operator */
    VECTOR_TEST(assignation);

    /* iterator */
    VECTOR_TEST(begin_end);
    VECTOR_TEST(rbegin_rend);

    /* capacity */
    VECTOR_TEST(size_capacity);
    VECTOR_TEST(max_size);
    VECTOR_TEST(resize);
    VECTOR_TEST(empty);
    VECTOR_TEST(reserve);
    VECTOR_TEST(reserveExcept);

    /* element access */
    VECTOR_TEST(accessOperator);
    VECTOR_TEST(at);
    VECTOR_TEST(atExcept);
    VECTOR_TEST(front_back);

    /* modifiers */
    VECTOR_TEST(assign0);
    VECTOR_TEST(assign1);
    VECTOR_TEST(push_back);
    VECTOR_TEST(pop_back);
    VECTOR_TEST(insert0);
    VECTOR_TEST(insert1);
    VECTOR_TEST(insert2);
    VECTOR_TEST(erase0);
    VECTOR_TEST(erase1);
    VECTOR_TEST(swap);
    VECTOR_TEST(clear);
}

int main()
{
    CompareTester ct;
    ct.setPrintOnPass(true);

    // testList(ct);
    // testListDouble(ct);
    testVector(ct);

    ct.printTotalScore();
    system("leaks ft_containers");
}
