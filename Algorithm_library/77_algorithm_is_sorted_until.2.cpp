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
/// is_sorted_until
// Examines the range [first,last) and finds the largest range beginning
// at first in which the elements are sorted in ascending (to rise, to go up, to climb up)
// The first version of function use operator < to compare the elements, the
// second uses the given comparison function comp.


#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>


 #include <random>
// #include <cstdlib>
// #include <ctime>



int main(){
    int num[]={4,3,2,1,0,1,2,3,4,5,6,7,2,1};
    int* numBeg=num;                            // point index[0]
    int* numEnd=num+(sizeof(num)/sizeof(int));  // point to index[ last+1 ], in use, we need to subtract it form 1

    int* end_sort = std::is_sorted_until(numBeg,numEnd-1,[](int a,int b){return a>b;});

    std::for_each(numBeg,end_sort,[](int i){std::cout<<i<<' ';});
    // or
    // while( numBeg != end_sort) std::cout<<*numBeg++<<' ';


}
