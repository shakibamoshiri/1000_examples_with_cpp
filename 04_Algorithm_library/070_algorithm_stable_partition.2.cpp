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

Partitioning Operation

    is_partitioned      determines if the range is partitioned by the give predicate
    partition           divides a range of elements into two groups
    partition_copy      copies a range dividing the elements into two groups
    stable_partition    divides elements into two groups while preserving their relative order
    partition_point     locates the partition point of a partitioned range
*/
/// stable partition
// Reordered elements in the range [fist, last) in such a way that all
// element for which that predicate p returns true precede the elements
// for which predicate p returns false. Relative order of the element is preserved.

#include <iostream>
#include <algorithm>
#include <iomanip>


#include <iterator>




// #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    std::vector<int> v{0,2,4,5,6,0,0,7,0,8,0,9,0};
    // what if we want to remove all zero?
    // Well, the std::stable_partition return the iterator to the first element on the second part
    // vector.erase() get two argument
    // One for the beginning point and another to the ending point
    // The element between the iterator is erased
    //
    // so we can
    v.erase(
    std::stable_partition(v.begin(),v.end(),[](int i){return i>0;}), // beginning  of i < 0, first element of the second part
    std::end(v));                                                    // end of container

    for(const int i:v)std::cout<<i<<' ';
}










