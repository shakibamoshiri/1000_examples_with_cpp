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

Sorting Operation

    is_sorted           checks whether a range is sorted into according order
    is_sorted_until     finds the largest sorted subrange
    sort                sorts a range into according order
    partial_sort        sorts the first N elements of a range
    partial_sort_copy   copies and partially sort a range of elements
    stable_sort         sorts a range of elements while preserving order between equal elements
    nth_elements        partially sorts the given range making sure that it is partitioned by the given elements

*/
/// is_sorted
// Checks if the elements in the range [first, last) are sorted in according order.
// It has two version. The first version uses operator < to compare the elements,
// the second version uses the given comparison function comp.

#include <iostream>
#include <algorithm>
#include <iomanip>


#include <iterator>




// #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    int arr[]={3,1,5,6,3,5,7,3,4,6,7,3};

    for(const int i:arr) std::cout<<i<<' ';
    // Before sort
    std::cout<<"Is arr sorted:\t"<<std::is_sorted(arr,arr+(sizeof(arr)/sizeof(int)))<<'\n';
    // Doing sort
    std::sort(arr,arr+(sizeof(arr)/sizeof(int)));

    for(const int i:arr) std::cout<<i<<' ';
    // After soft
    std::cout<<"Is arr sorted:\t"<<std::is_sorted(arr,arr+(sizeof(arr)/sizeof(int)))<<'\n';


}










