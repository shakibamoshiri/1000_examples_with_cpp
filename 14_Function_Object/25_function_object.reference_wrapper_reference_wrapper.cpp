/*
            Function Object
            ***************

3. Reference Wrapper
    3.1 reference_wrapper
        std::reference_wrapper is a class template that wraps a reference
        in a copyable, assignable object. It is frequently used as a mechanism
        to store reference inside standard containers (like: std::vector) which
        cannot normally hold reference.

    --------------------------------------------
    3.2 ref and cref
        Function template ref and cref are helper function that generate
        an object of type std::reference_wrapper, using template argument
        deduction to determine the template argument of type result.

*/
///  std::reference_wrapper

#include <iostream>
#include <functional>
#include <list>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>


int main() {

    std::list< int > list (10);
    std::iota( list.begin(), list.end(), -4 );  // filling the list from -4 to 5

    std::vector< std::reference_wrapper< int > > vector (list.begin(), list.end());

    // cannot use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle( vector.begin(), vector.end(),
                 std::mt19937( std::random_device{}() ) );

    std::cout << "contents of the list:\n";
    for (const int i : list) std::cout << i << ' ';
    // after for
    std::cout << std::endl;

    std::cout << "contents of the list, as seen through a shuffled vector:\n";
    for (const int i : vector) std::cout << i << ' ';
    // after for
    std::cout << std::endl;

    std::cout << "doubling the values in the initial list...\n";
    for (int& i : list) i *= 2;

    std::cout << "contents of the list, as seen through a shuffled vector:\n";
    for (const int i : vector) std::cout << i << ' ';


}


/* output for me:

contents of the list:
-4 -3 -2 -1 0 1 2 3 4 5
contents of the list, as seen through a shuffled vector:
0 1 4 -3 -1 -2 5 2 3 -4
doubling the values in the initial list...
contents of the list, as seen through a shuffled vector:
0 2 8 -6 -2 -4 10 4 6 -8

*/


