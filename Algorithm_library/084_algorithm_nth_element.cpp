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
/// nth_elements
// returning value nothing
//
// nth_element is a partial sorting algorithm that rearranges elements in
// [first, last) such that:
// * The element pointed at by nth is changed to whatever element would occur
//   in that position if [first,last) was sorted
// * All of the elements before this new nth element are less than or equal to
//   the elements after the new nth element.


#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
// #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    typedef std::vector<int> vecInt;

    vecInt v{5,6,4,3,2,6,7,9,3};

    std::nth_element(v.begin(),                     // beginning
                     std::begin(v) + v.size()/2,    // what position do you want?
                     v.end());                      // ending
    std::cout<<"The median is "<<v[v.size()/2]<<'\n';

    std::cout<<"\nv:\t";
    for(const int i:v){ if (i==v[v.size()/2]) std::cout<<'*'<<i<<' '; else std::cout<<i<<' ';}
}









