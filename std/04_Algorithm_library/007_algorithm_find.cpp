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




/// std::find, std::find_if, and std::find_if_not(c++11)
//
// std::find:       searches for an elements equal to value
// std::find_if     searches for an elements for which predicate p return true
// std::find_if_not searches for an elements for which predicate p return false



#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>




int main(){
    int n1 = 3;
    int n2 = 5;

    std::vector<int> v{0,1,2,3,4};

    // searches form 0 to 4, looking for 3
    // auto is the same as std::vector<int>::iterator
    std::vector<int>::iterator result1 = std::find(std::begin(v),std::end(v), n1);
    auto result2 = std::find(std::begin(v),std::end(v), n2);

    if(result1 != std::end(v))      // it means not equal to null
        std::cout<<"v contains: "<<n1<<std::endl;
    else
        std::cout<<"v does not contains: "<<n1<<std::endl;

    if ( result2 != std::end(v) )   // not equal to null, ( the end iterator is null always )
        std::cout<<"v contains: "<<n2<<std::endl;
    else
        std::cout<<"v does not contains: "<<n2<<std::endl;

}
