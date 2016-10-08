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


int main(){
    std::string one("ABCDE");
    std::string two("ABcde");

    // test if the two first letter in different strings are equal
    // This compare one:AB with two: AB
    if (std::equal(one.begin(),one.begin()+2,two.begin(),two.begin()+2))
        std::cout<<"okay";

    // Also test if the two last letter in different string are equal
    // This compare one: ED with two: ed
    if (! std::equal(one.rbegin(),one.rbegin()+2, two.rbegin(),two.rbegin()+2))
        std::cout<<"\nNO, are not equal\n";

    // This sample needs more knowledge on iterator
    // if you do not understand what syntax does,
    // go and read iterator library, then back here
    std::cout<<"one.rbegin()+2 is: ";
    std::for_each(one.rbegin(),one.rbegin()+2,[](char h){ std::cout<<h; });

    std::cout<<"\ntwo.rbegin()+2 is: ";
    std::for_each(two.rbegin(),two.rbegin()+2,[](char h){ std::cout<<h; });
}
