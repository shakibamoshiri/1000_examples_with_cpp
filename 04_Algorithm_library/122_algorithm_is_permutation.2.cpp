/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.
------------------------------------------------------------------
You can read the original implementation in:
stl_algobase.h and stl_algo.h and algorithmfwd.h
------------------------------------------------------------------
Defined in header <algorithm>

Maximum / Minimum Operation

    max                 returns the greater of the given value
    max_element         returns the largest element in a range
    min                 returns the smaller of the given value
    min_element         returns the smallest element in a range
    minmax              returns the larger and the smaller of two elements
    minmax_element      returns the smallest and the largest elements in a range
    lexicographical_compare         returns true if one range is lexicographically less than another
    is_permutation      determines if a sequence is a permutation of another sequence
    next_permutation    generates the next larger lexicographic permutation of a range of elements
    prev_permutation    generates the next smaller lexicographic permutation of a range of elements

*/
/// is_permutation
// Returns true if there exists a permutation of the elements in the range
// [first,last) that makes that range equal to the range [first2,last2).
// Two version of this function use operator == for equality, whereas
// another two version use the binary predicate

#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
// #include <random>
 // #include <cstdlib>
 // #include <ctime>
// #include <unistd.h>


int main(){

    std::vector<char> one {'a','b','c','d'};
    std::vector<char> two {'a','c','b','d'};
    std::vector<char> three {'a','c','b','e'};      // this is not a permutation of one and two

    /* permute a,b,c, is:
    a b c
    a c b
    c a b
    b a c
    b c a
    c b a
    */

    std::boolalpha(std::cout);

    std::cout<<"one is a permutation of two:\t"<<std::is_permutation(one.begin(),one.end(),two.begin(),two.end())<<std::endl;
    std::cout<<"one is a permutation of three:\t"<<std::is_permutation(one.begin(),one.end(),three.begin(),three.end())<<std::endl;
    std::cout<<"two is a permutation of three:\t"<<std::is_permutation(two.begin(),two.end(),three.begin(),three.end())<<std::endl;
    // one and two:     true
    // two and one:     true
    // one and three:   false
    // two and three:   false
    // three and one:   false
    // three and two:   false

return 0;}









