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
/// set_difference
// Copies the elements from the sorted range [first1,last1) which are not
// found in the sorted range [first1,last1) to the range beginning at d_first.
// The resulting range is also sorted. The first version expects both input
// ranges to be sorted with operator <, the second version expects them to be
// sorted with the given comparison function comp.


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
    std::vector<int> one{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> two{2,4,6,8};


    std::vector<int> out;

    std::set_difference(one.begin(),one.end(),
                        two.begin(),two.end(),
                        std::back_inserter(out),
                        // for a < b, the output is:    0 1 3 5 7 9             correct
                        [](int a,int b){return a<b;});
                        // for a > b, the output is:    0 1 2 3 4 5 6 7 8 9     only one
                        // for a == b, the output is:   4 5 6 7 8 9             one except two

    std::cout<<"The difference is:\t";
    for(const int i:out) std::cout<<i<<' ';
}







