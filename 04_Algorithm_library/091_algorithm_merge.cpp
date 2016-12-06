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
/// marge
// Merges two sorted ranges [first,last) and [first2,last2) into one sorted range
// beginning at d_first.
// The first version uses operator < to compare
// and the second version uses comparison function.
// The relative order of equivalent elements is preserved.
// The behavior is undefined if the destination range overlaps either of the input
// ranges ( the input ranges may overlap each other)
//
// Return value: an output iterator to element past the last element copied.
//
// This algorithm performs a similar task as std::set_union does.
// Both consume two sorted input range and produced a sorted output
// with elements from both inputs. The difference between these two
// algorithm is with handling value from both input ranges which compare
// equivalent
// For more detail see the main site.


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
    // fill the vectors with random number
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dis(0,9);

    std::vector<int> vec1(10), vec2(10);

    std::generate(vec1.begin(), vec1.end(), std::bind(dis, std::ref(mt)));
    std::generate(vec2.begin(), vec2.end(), std::bind(dis, std::ref(mt)));

    // sort
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    // vec1 output:
    std::cout<<"vec1:\t";
    for(const int i:vec1)std::cout<<i<<' ';

    // vec2 output:
    std::cout<<"\nvec2:\t";
    for(const int i:vec2)std::cout<<i<<' ';

    // merge
    std::vector<int> dst;
    std::merge(std::begin(vec1),std::end(vec1),         // first       => vec1
               std::begin(vec2),std::end(vec2),         // second      => vec2
               std::back_inserter(dst));                // destination => dst

    // total output:
    std::copy(std::begin(dst), std::end(dst), std::ostream_iterator<int>(std::cout<<"\nmerge:\t"," "));
}







