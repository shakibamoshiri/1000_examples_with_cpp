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
/// set_symmetric_difference
// Computes symmetric difference of two sorted range: the element that are found
// in either of the ranges, but not both of them are copied to the range beginning
// at d_first. The resulting range is also sorted.
// The first version expects both input ranges to be sorted with operator <, the
// second version expects them to be sorted with the given comparison function comp.


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





int main(){

    std::vector<int> v1{1,2,3,4,5,6,7,8     };
    std::vector<int> v2{        5,  7,  9,10};

    // sorting
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());

    // using
    std::set_symmetric_difference(
                                  v1.begin(),v1.end(),
                                  v2.begin(),v2.end(),
                                  std::copy(v2.begin(),v1.end(),std::ostream_iterator<int>(std::cout<<"output:\t"," ")),
                                  [](int a,int b){return a<b;}); // using function comp

return 0;}










