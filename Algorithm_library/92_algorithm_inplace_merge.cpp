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

Set operation ( or sorted range )

    merge               merges two sorted range
    inplace_merge       merges two ordered range in-place
    includes            return true if one set is a subset of another
    set_difference      computes the difference between two sets
    set_intersection    computes the intersection of two sets
    set_symmetric_difference        computes the symmetric difference between two sets
    set_union           computes the union of two sets

*/
/// inplace_marge
// Merges two consecutive sorted range [first,middle) and [middle, last)
// into one sorted range [first,last). The order of equal elements is
// guaranteed to be preserved.
// The first version uses operator < to compare,
// and the second, uses the given comparison function comp.

#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
#include <random>
// #include <cstdlib>
// #include <ctime>

template<typename Iter> void merge_sort (Iter first, Iter last){
    if(last - first > 1){
        Iter middle = first + ( last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle,last);
        std::inplace_merge(first,middle,last);
    }
}


int main(){
    std::vector<int> vec{-1,3,-4,-4,33,43,1,34,98,0,9,7,7,7,2};

    merge_sort(vec.begin(), vec.end());

    std::vector<int>::iterator itbeg=std::begin(vec);
    std::cout<<"The output:\t";
    while(itbeg != std::end(vec))std::cout<<*itbeg++<<' ';
}







