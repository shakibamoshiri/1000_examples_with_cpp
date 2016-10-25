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


int main(){

    std::initializer_list<const char*> il{"the","brown","quick","fox"}; // object of initializer_list

    // return an iterator to the greatest element
    // so we store it
    // by an iterator and by a const char*
    std::initializer_list<const char*>::iterator list_it = std::max_element(il.begin(),il.end());

    std::cout<<*list_it<<std::endl;

    // with const char*
    const char* char_it = *std::max_element(il.begin(),il.end()); // return the address of greatest, and * dereferences it

    std::cout<<char_it<<std::endl;


    std::cout<<"The greatest element is at:\t"<<std::distance(il.begin(),list_it)<<std::endl;



return 0;}










