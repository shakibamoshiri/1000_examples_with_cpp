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

Sorting Operation

    is_sorted           checks whether a range is sorted into according order
    is_sorted_until     finds the largest sorted subrange
    sort                sorts a range into according order
    partial_sort        sorts the first N elements of a range
    partial_sort_copy   copies and partially sort a range of elements
    stable_sort         sorts a range of elements while preserving order between equal elements
    nth_elements        partially sorts the given range making sure that it is partitioned by the given elements

*/
/// partial sort copy
// Sorts some of the elements in the range [first, last) in ascending order,
// sorting the result in the range[d_first, d_last). (see implementation in the main site)



#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>
#include <functional>

// #include <array>
// #include <random>
// #include <cstdlib>
// #include <ctime>




int main(){
    std::vector<int> v0{4,2,5,1,3};
    std::vector<int> v1{10,11,12};
    std::vector<int> v2{10,11,12,13,14,15,16};
    std::vector<int>::iterator itv;

    itv = std::partial_sort_copy(v0.begin(),v0.end(),v1.begin(),v1.end()); // copy form v0 to v1
    // partial_sort_copy, returns an iterator to the element definition the upper boundary of the sorted range,
    // i.e. d_first + min ( last - first, d_last - d_first).

    std::cout<<"writing to the smaller vector in ascending order gives:\t";
    for(const int i:v1)std::cout<<i<<' '; std::cout<<'\n';

    if(itv==v1.end()) std::cout<<"returned value is the end iterator\n";

    itv = std::partial_sort_copy(v0.begin(),v0.end(),v2.begin(),v2.end(),std::greater<int>());

    std::cout<<"writing the larger vector in the ascending order gives:\t";
    for(const int i:v2)std::cout<<i<<' '; std::cout<<'\n';

    std::cout<<"The return value in the iterator to "<<*itv<<'\n'; // point to 15 in {5,4,3,2,1,15,16}
}

