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
/// min_element
// Fins the smallest element in the range [first,last).
// One version uses operator < to compare the value, and
// the other one uses the given comparison function
//
// Return value:
// return an iterator to the smallest element in the range

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

    std::vector<int> vec {9,4,1,3,1,5,1,8}; // 1 is the smallest

    std::vector<int>::iterator itvec = std::min_element(vec.begin(),vec.end());
    // because if several elements in the range are equivalent to the smallest,
    // std::min_element returns the iterator to the first element, so here
    // return iterator to position 2
    // [0] => 9
    // [1] => 4
    // [2] => 1 smallest
    std::cout<<"The smallest value is at position:\t"<<std::distance(vec.begin(),itvec)<<'\n';

return 0;}










