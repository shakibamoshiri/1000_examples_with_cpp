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
/// partial_sum
// Computes the partial sums of the elements in the subranges of the range
// [first,last) and writes them to the range beginning at d_first.
// One version uses operator + to sum up the element, and the other
// version uses the given binary function.
//
// Return Value
// Iterator to the element past the last element written



#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
#include <string>

// #include <array>
#include <list>
#include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>


int main(){

    std::vector<int> vector(10,1); // {1,1,1,1,1,1,1,1,1,1}

    std::partial_sum(vector.begin(),vector.end(),vector.begin());  // 1,2,3, ...
    std::cout<<"After doing partial_sum(vector):\t";
    for(const int i:vector)std::cout<<i<<' ';

    for(int& i:vector) i=2;         // all element are 2 now

    std::partial_sum(vector.begin(),vector.end(),               // input
                     std::ostream_iterator<int>(std::cout<<"\nAfter doing partial_sum(vector) again:\t"," ")); // output
                     // by default plus each element

    std::partial_sum(vector.begin(),vector.end(),       // input
                     std::ostream_iterator<int>(std::cout<<"\nDoing partial_sum with Binary_Function:\t"," "),  // output
                     std::multiplies<int>());   // multiplies each element ( BinaryFunction )


return 0;}







