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
/// stl_algobase.h and stl_algo.h and algorithmfwd.h

#include <iostream>
#include <algorithm>
#include <vector>
// #include <iterator>




/// search_n            search for a member consecutive copies of an element in a range
// Searches the range [first, last) for the first sequence of count identical element
// ,each equal to the given value value.
//
// return type:
// An iterator to the beginning of the found sequence in the range
// [first, last). If no such sequence is found, last is returned.
template<typename T>
short consecutive_found(T& tmp,const char ch){
    short count=0;
    short bank=0;

    for(char c : tmp){

        if(c != ch)         count=0;
        if(c == ch)         ++count;
        if(count > bank)    bank=count;

    }
    return bank;
}


int main(){
    const char sequence[]="100101010001000001101001010101";
    std::cout<<consecutive_found(sequence,'1')<<std::endl;
    std::cout<<consecutive_found(sequence,'0')<<std::endl;
    std::cout<<consecutive_found(sequence,'2')<<std::endl;
}

