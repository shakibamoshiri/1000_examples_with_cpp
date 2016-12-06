/*
Algorithm Library C++
The algorithm library defines functions for a variety of purposes.
(e.g. searching, sorting, counting, manipulating ) that operate on
range of elements. Note that a range is defined as [ first, last )
where last refers to the element past the last element to inspect
or modify.

Defined in header <algorithm>

Non-modifying sequence operation
    all_of
    any_of
    noun_of             check, if the predicate is true for all, any, or none of the element is a range
    for_each            applies a function to a range of element

    count
    count_if            return the number of elements satisfying specific criteria
    mismatch            find the first position, where to ranges differ
    equal               determines if two set of elements are the same
    find
    find_if
    find_if_not         find the first element satisfying specific criteria
    find_end            find the last sequence of elements in certain range
    find_first_of       search for any one of a set of elements
    adjacent_find       find the first two adjacent items that are equal (or satisfy a given predicate)
    search              searches for a range of elements
    search_n            search for a number consecutive copies of an element in a range.
*/
/// You can read the original implementation in:
/// stl_algobase.h and stl_algo.h

#include <iostream>
#include <algorithm>

/// std::mismatch
// Returns the first mismatching pair of elements form two ranges:
// one defined by [first1, last1) and another defined by [first2,
// last2 ), if last2 is not provided (overload (1,2)), it denotes
// first2 + (last1 - first1).
// For read more detail, see the mine site: en.cppreference.com


#include <string>

std::string mirror_ends(const std::string& t){
    return std::string(t.begin(), std::mismatch(t.begin(),t.end(),t.rbegin()).first);
}

int main(){
    std::cout << mirror_ends("abXYZba") << std::endl;
    std::cout << mirror_ends("abXYZXba") << std::endl;
    std::cout << mirror_ends("abca") << std::endl;
    std::cout << mirror_ends("aba") << std::endl;
    std::cout << mirror_ends("abccba") << std::endl;
}
