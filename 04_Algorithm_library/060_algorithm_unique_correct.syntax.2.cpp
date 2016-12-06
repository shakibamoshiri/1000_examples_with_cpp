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

Modifying sequence operation
    copy
    copy_if             copies a range of elements to a new location
    copy_n              copies a number of elements to a new location
    copy_backward       copies a range of elements in backward order
    move                moves a range of elements to a new location
    move_backward       moves a range of elements to a new location in backward order
    fill                assigns a range of elements a certain value
    fill_n              assigns a value to a number of elements
    transform           applies a function to a range of elements
    generate            saves the result of a function in a range
    generate_n          saves the result of N applications of a function
    remove
    remove_if           removes elements satisfying specific criteria
    remove_copy
    remove_copy_if      copies a range of elements omitting those that satisfy specific criteria
    replace
    replace_if          replaces all value satisfying specific criteria with another value
    replace_copy
    replace_copy_if     copies a range, replacing elements satisfying specific criteria with another value
    swap                swaps the value of two objects
    swap_range          swaps the two range of elements
    iter_swap           swaps the elements pointed to by two iterator
    reverse             reverses the order of elements in a ragne
    reverse_copy        creates a copy of a range that is reversed
    rotate              rotate the order of elements in a range
    rotate_copy         copies and rotate a range of elements
    shuffle
    random_shuffle      randomly re-orders elements in a range

    (until c++ 17)(c++11)
    unique              removes consecutive duplicate element in a range
    unique_copy         creates a copy a of some range of elements that contains no consecutive duplicate
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

// #include <random>
// #include <cstdlib>
// #include <ctime>

/// (until c++ 17)(c++11)
/// unique              removes consecutive duplicate element in a range
/// unique_copy         creates a copy a of some range of elements that contains no consecutive duplicate
// Removes all consecutive duplicate elements from the range [ first, last )
// and returns past-the-end iterator for the new logical end of the range.
//
// Removing is down by shifting the elements in the range in such a way
// that elements to be erased are overwriting.
//
// Relative order of the elements that remain is preserved and the physical
// size of the container is unchanged. iterator pointing to an element
// between the two logical end and the physical end of the range are
// still dereferenceable, but the elements themselves have unspecified
// value.
//
// A call to unique is typically followed by a call to a container's erase method,
// which erases the unique unspecified value and reduces the physical size
// of the container to match its new logical size.



int main(){

    // remove duplicate elements
    std::vector<int> vec{1,2,3,2,5,6,1,8,9,1,2,1,3,4,5,6,7,8};

    std::sort(vec.begin(),vec.end());
    std::vector<int>::iterator last = std::unique(vec.begin(),vec.end());

    vec.erase(last,vec.end());

    // Although it is sorted, but it still needs to be erased
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout<<"vec:\t"," "));
}














