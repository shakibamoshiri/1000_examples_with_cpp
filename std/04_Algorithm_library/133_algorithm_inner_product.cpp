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
/// inter_produce
// Computes inner products (i.e. sum of products) of the range [first1,last1)
// and another range beginning at first2.
// One version uses operator * to computes products of the element pair
// and operator + to sum up the products, the second version uses
// BinaryOperation1 and BinaryOperation2 for these takes respectively. ( it mean one after another )
//
// Return Value
// the inner product of two ranges

#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
#include <string>

// #include <array>
#include <list>
#include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>

/*
//  custom implementation of std::accumulate
template<typename T,typename C>
T accumulate (C first, C last){

    T sum=0;

    while(first != last) sum += *first++;

    return sum;
}
*/

int main(){

    int one[]{0,1,2,3,4};
    int two[]{5,4,2,3,1};

    int r1 = std::inner_product(std::begin(one),std::end(one),std::begin(two),0);
    std::cout<<"Inner product of one and two:\t"<<r1<<std::endl;

    int r2 = std::inner_product(std::begin(one),std::end(one),std::begin(two),0,
                                std::plus<int>(),
                                std::equal_to<int>());
    std::cout<<"Number of pairwise matches between one and two:\t"<<r2<<std::endl;
return 0;}







