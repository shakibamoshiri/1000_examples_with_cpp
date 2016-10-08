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




/// find_first_of       search for any one of a set of elements
// Searches the range [first,last) for any of the elements in the range
// [s_first, s_last).
//
// return value:
// iterator to the first element in the range


template<class It,class Fw>
It ffo(It first, It last, Fw s_first, Fw s_last){
    for(; first != last;++first)
        for(Fw fit = s_first; fit != s_last; ++fit)
            if(*first == *fit)
            return first;

    return last;
}



int main(){
    std::vector<int> vec{0,2,3,25,5};
    std::vector<int> tmp{3,19,10,2};

    // in           vec
    // search for   tmp
    std::vector<int>::iterator rst = ffo(vec.begin(), vec.end(),tmp.begin(),tmp.end());

    if ( rst == std::end(vec) )
        std::cout<<"no elements of vec were equal to tmp\n";
    else
        std::cout<<"found match is at: "<<std::distance(std::begin(vec),rst);

    std::cout<<"\nfound match is: "<<vec[*rst];

}
