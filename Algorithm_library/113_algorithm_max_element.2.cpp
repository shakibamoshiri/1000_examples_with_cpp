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
/// max_element
// Fins the greatest element in the range [first,last).
// The first version uses operator < to compare the value,
// and the second version uses the given comparison function comp.
//
// Return value:
// Iterator to the greatest value in the range [first,last).
// If several element in the range are equivalent to the greatest
// element, returns the iterator to the first such element.
// Reruns last if the list is empty.


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

static bool abs_compare(int a,int b){ return (std::abs(a)<std::abs(b)); }


int main(){

    std::vector<int> vec{3,1,-14,1,5,9};
    std::vector<int>::iterator result;

    result = std::max_element(vec.begin(),vec.end());
    std::cout<<"max element at position:\t"<<std::distance(vec.begin(),result)<<std::endl;

    // using abs_compare
    result = std::max_element(vec.begin(),vec.end(),abs_compare);
    std::cout<<"max element (absolute) at position:\t"<<std::distance(vec.begin(),result)<<std::endl;


return 0;}










