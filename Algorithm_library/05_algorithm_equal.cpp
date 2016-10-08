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

/// std::equal
// Two implementation return true if the range [first,last) is equal to the range
// [first2, first2 + ( last1 - first1 )), and false otherwise.
// Another two implementation return true if the range [first, last) t equal to the range
// [first2, last2) and false otherwise.
//
//
// Example
// The following code uses equal() to test if a string is a palindrome ( madam == madam )

#include <string>


bool is_palindrome(const std::string& s){
    return std::equal(s.begin(),s.begin()+s.size()/2,s.rbegin());
}

int main(){

 if ( is_palindrome("madam") )
    std::cout<<"Oh, madam is a palindrome\n";

 if ( !is_palindrome("k-five") )
    std::cout<<"Are you kidding me? Of course it is not a palindrome\n";
}
