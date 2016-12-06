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

Maximum / Minimum Operation

    max                 returns the greater of the given value
    max_element         returns the largest element in a range
    min                 returns the smaller of the given value
    min_element         returns the smallest element in a range
    minmax              returns the larger and the smaller of two elements
    minmax_element      returns the smallest and the largest elements in a range
    lexicographical_compare         returns true if one range is lexicographically less than another
    is_permutation      determines if a sequence is a permutation of another sequence
    next_permutation    generates the next larger lexicographic permutation of a range of elements
    prev_permutation    generates the next smaller lexicographic permutation of a range of elements

*/
/// minmax_element
// Finds the greatest and the smallest element in the range [first,last).
// The first version uses operator < to compare, and the second
// version uses the given comparison function
//
// Return value:
// A pair consisting of an iterator to the smallest element as the first element
// and an iterator to the greatest element as the second.
// If several elements are equivalent to the smallest element, the iterator
// to the first such element is returned.
// If several elements are equivalent to the greatest element, the iterator
// to the last such element is returned.
// So
// smallest, iterator to the first in several item
// greatest, iterator to the last in several item

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

    std::vector<int> one {3,2,1,2,1,4,5,6,9,7,8,9};
    // one has two smallest at one[2] and one[4]
    // one has two largest  at one[8] and one[11]
    // so std::pair returns first 1 for smallest    at position [2]
    // and returns last 9 for largest               at position [11]

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> it_min_max_one = std::minmax_element(one.begin(),one.end());

    /*  I comment this part because I was confused with the return address of iterator and std::pair iterator
        If you do not confuse with this part you no need to read it.

    std::vector<int>::iterator first=std::begin(one);   // iterator to begging of the one

    // with points to the data of one
    // the address of index[2] with iterator and std::pair and int*
    // all of three point to the same address and the have the same value
    std::cout<<*(first+2)<<"\t"<<&(*(first+2))<<std::endl;                          // data and address of data with iterator of index[2], okay
    std::cout<<*it_min_max_one.first<<"\t"<<&(*it_min_max_one.first)<<std::endl;    // data and address of data with std::pair of index [2], okay
    const int* beg_one = &(*std::begin(one));
    std::cout<<*(beg_one+2)<<"\t"<<beg_one+2<<std::endl;                            // data and address of data with pointer of index[2], okay

    // but with iterator of one, it has the same address with the different value
    std::cout<<"\nwith the iterator of one\n";
    std::cout<<*(first+2)<<"\t"<<&first+2<<std::endl;                           // iterator to index[2] has a difference address, I am confusing ):
    std::cout<<*it_min_max_one.first<<"\t"<<&it_min_max_one.first<<std::endl;   // this iterator should return index [2], okay I understand
    */

    std::cout<<"Smallest:\t"<<*it_min_max_one.first<<"\nLargest:\t"<<*it_min_max_one.second<<'\n';
    std::cout<<"The index of smallest is: "<<std::distance(std::begin(one),it_min_max_one.first)<<'\n';
    std::cout<<"The index of largest is: "<<std::distance(std::begin(one),it_min_max_one.second)<<'\n';


return 0;}










