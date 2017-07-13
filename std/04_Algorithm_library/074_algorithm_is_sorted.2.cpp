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
    bool (*comp)(int,int) = [](int a,int b){return a>b;}; // It means if element one > element two
    std::cout<<"Is sorted:\t"<<std::is_sorted(arr,arr+(sizeof(arr)/sizeof(int))-1,comp)<<'\n'; // here not

    std::sort(arr,arr+(sizeof(arr)/sizeof(int)));
    for(const int i:arr) std::cout<<i<<' ';
    std::cout<<"Is sorted:\t"<<std::is_sorted(arr,arr+(sizeof(arr)/sizeof(int))-1,comp)<<'\n'; // here not

    std::reverse(arr,arr+(sizeof(arr)/sizeof(int)));
    for(const int i:arr) std::cout<<i<<' ';
    std::cout<<"Is sorted:\t"<<std::is_sorted(arr,arr+(sizeof(arr)/sizeof(int))-1,comp)<<'\n'; // here okay

    // custom for-base-range
    int* end_of_arr=arr+(sizeof(arr)/sizeof(int));
    for (int* begin_of_arr = arr; begin_of_arr != end_of_arr; ++begin_of_arr) std::cout<<*begin_of_arr<<' ';

    std::cout<<'\n';

    // or:
    const int* beg_arr=arr;
    const int* const end_arr=arr+(sizeof(arr)/sizeof(int));
    while( beg_arr != end_arr ) { std::cout<<*beg_arr<<' '; beg_arr++; }

    /// note:
    // arr+(sizeof(arr)/sizeof(int)) => point to one index after last index of array
    // so the locate of the end of array is arr + ( sizeof(arr)/sizeof(int) ) - 1
}










