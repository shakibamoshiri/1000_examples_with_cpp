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
/// min
// Returns the smaller of the given values
// implementation 1,2 ) returns the smaller of a and b
// implementation 3,4 ) returns the smallest of the value in initializer_list object

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

    std::cout<<std::min(2,4)<<std::endl;        // numeric

    std::cout<<std::min("A","C")<<std::endl;    // character

    std::cout<<std::min("hello","world")<<std::endl;    // string

    std::cout<<std::min({1,3,4,-3,-7,0})<<std::endl;     // numeric, initializer_list

    std::cout<<std::min({"how", "are", "you", "today"})<<std::endl;     // string, initializer_list

return 0;}










