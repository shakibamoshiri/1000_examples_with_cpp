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
/// max
// Returns the grater of the giving values
// It has four implementation
// 1,2 ) returns the greater of a and b
// 3,4 ) returns the greatest of the values in initializer list ilist
//
// NOTE:
// Capturing the result of std::max by reference if one of the parameter
// is r-value produces a dangling reference if that parameter is returned.



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

    std::cout<<std::max(1,2)<<std::endl;        // numeric

    std::cout<<std::max('a','b')<<std::endl;    // character

    std::cout<<std::max({"how","are","you","today?"})<<std::endl; // initializer_list

    std::initializer_list<const char*> il{"the","brown","quick","fox"}; // object of initializer_list

    const char* max_return = std::max(il);      // return value of max

    std::cout<<max_return<<std::endl;

return 0;}










