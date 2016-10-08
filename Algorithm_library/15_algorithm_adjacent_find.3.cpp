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




/// adjacent_find       find the first two adjacent items that are equal (or satisfy a given predicate)
// Searches the range [first, last) for two consecutive identical element.
// One of its implementation use operator == to compare the elements
// and another one uses given binary predicate p ( set the main site)


int main(){
    std::vector<int> vt{0,1,2,3,40,40,41,41,5};
    auto itv = std::adjacent_find(vt.begin(),vt.end(),std::greater<int>());
    if(itv==vt.end())
        std::cout<<"The entire vector is sorted in according order\n";
    else
        std::cout<<"The last element in the non-decreasing subsequence is at: "
                 <<std::distance(vt.begin(),itv);

    std::cout<<"\nthat it is: "<<*itv;

}
