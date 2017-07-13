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




/// std::find_end
// searches for the last subsequent of elements [s_first, s_last) in the range
// [first, last). One version uses operator == to compare the elements, and
// one version uses the given binary predicate value.
//
// Returns value:
// Iterator to the beginning of last subsequent


// The following code use find_end() to search for two different sequences of numbers

int main(){
    std::vector<int> v{1,2,3,4,1,2,3,4,1,2,3,4};
    std::vector<int> temp{1,2,3};

    std::vector<int>::iterator itv;

    itv = std::find_end(v.begin(),v.end(), temp.begin(),temp.end());
    if( itv == v.end())
        std::cout<<"subsequent not found\n";
    else
        std::cout<<"last subsequence is at: "
                 <<std::distance(v.begin(),itv);

    std::vector<int> temp2{4,5,6};
    itv = std::find_end(v.begin(),v.end(),temp2.begin(),temp2.end());
    if(itv == std::end(v))
        std::cout<<"\nsubsequence not found\n";
    else
        std::cout<<"okay, found at: "<<std::distance(v.begin(),itv);
}
