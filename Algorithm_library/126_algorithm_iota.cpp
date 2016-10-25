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

Numeric Operation

    iota                fills a range with successive increments of a string value
    accumulate          sums up a range of elements
    inner_product       computes the inner product of two range of elements
    adjacent_difference computes the difference between adjacent elements in a range
    partial_sum         computes the partial sum of a range of elements

*/
/// iota ( meaning in Oxford: an exactly small amount )
/// example: There is not one iota of truth (= no truth at all) to the story
/// Also it is the ninth letter of the Greek alphabet
// Fills the range [first,last) with sequentially increasing values,
// starting with value ( the given value ) and repetitively evaluating ++value
// for example if the given value would be 0 the next is 1 then 2 like
// 0, 1, 2, 3, ... and so on


#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
// #include <random>
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>


int main(){

    std::vector<int> one(10);

    // fills the one vector from 0 to 9
    std::iota(one.begin(),one.end(),0);

    std::cout<<"one:\t";
    for (const int i:one)std::cout<<i<<' ';

    // if we set the first value that passed to iota it would be the first of container
    std::iota(one.begin(),one.end(),9);
    std::cout<<"\nThe given value is 9, so the new elements of one is:\t";
    for(const int i:one)std::cout<<i<<' ';



return 0;}









