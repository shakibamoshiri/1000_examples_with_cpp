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
/// adjacent_difference
// Computes the differences between the second and the first of each
// adjacent pair of elements of the range [first,last) and write them
// to the beginning at d_first + 1. Unmodified copy of first is written
// to d_first.
// One version used operator - to calculate the differences, the other
// version uses the given binary function.
//
// Return Value
// Iterator to the element past the last element written.
//
// NOTE:
// If first == last, this function has no effect and will merely return d_first.

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

void generate_respectively (std::vector<int>& vec,const int init){
    int* bv = &(*std::begin(vec));
    for(int i=1;i<(vec.size()+1); i++ ) *(bv++)=(i * init);
}

int main(){

    std::vector<int> vector(10,0);
    generate_respectively(vector,3); // vector: 3,6,9,...

    std::vector<int> diff (10,0);
    std::adjacent_difference(vector.begin(),vector.end(),diff.begin());
    std::cout<<"diff:\t";
    for (const int i:diff)std::cout<<i<<' ';        // 3 3 3 3 3 ...




return 0;}







