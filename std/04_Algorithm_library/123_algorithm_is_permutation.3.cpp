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

    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2{3,5,4,1,2};
    std::cout<<"3,5,4,1,2 is a permutation of 1,2,3,4,5? "
             <<std::boolalpha
             <<std::is_permutation(v1.begin(),v1.end(),v2.begin())<<'\n';
    std::vector<int> v3{3,5,4,1,1};
    std::cout << "3,5,4,1,1 is a permutation of 1,2,3,4,5? "
              << std::boolalpha
              << std::is_permutation(v1.begin(), v1.end(), v3.begin()) << '\n';

return 0;}









