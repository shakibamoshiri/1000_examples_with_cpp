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
/// set_intersection
// Constructs a sorted range beginning at d_first consisting of elements
// that are found in both sorted range [first1,last1) and [first2,last2).
// The first version expects both input ranges to be sorted with operator <
// the second version expects them to be sorted with the given comparison function comp

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
    std::vector<int> one{0,4,1,3,4,5,6,7,7,9};
    std::vector<int> two{2,4,6,8};


    std::vector<int> out;
    bool (*compFunc)(int,int)=[](int a,int b){return a==b;};        // if ( !comp(*first2, first1) )
                                                                    // if not 0 == 2 => true, so put 0 to output
                                                                    // if not 4 == 4 => false, ++first1
                                                                    // if not 1 == 6 => true, so put 1 to output
                                                                    // if not 3 == 8 => true, so out 3 to output
                                                                    // if not 4 = nothing => true, so put 4 to output
                                                                    // the output will 0 1 3 4

    std::set_intersection(one.begin(),one.end(),    // input one
                        two.begin(),two.end(),      // input two
                        std::back_inserter(out),    // output       // for more detail about set::back_inserter, see iterator library
                        compFunc);

    std::cout<<"The common values are:\t";
    for(const int i:out) std::cout<<i<<' ';
}







