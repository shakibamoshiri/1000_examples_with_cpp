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
    std::random_device rd;
    std::mt19937 g(rd());

    int num[]={3,1,4,1,5,9};
    int* numBeg=num;
    int* const numEnd=num+(sizeof(num)/sizeof(int)); // past-the-last element

    const int min_sort_size=4;
    int sorted_size=0;

    do{
        std::shuffle(numBeg,numEnd,g);
        int* sorted_end=std::is_sorted_until(numBeg,numEnd);
        sorted_size=std::distance(numBeg,sorted_end);

        for (const int i:num)std::cout<<i<<' ';
        std::cout<<" : "<<sorted_size<<" initial sorted elements\n";
    }while(sorted_size < min_sort_size);

}

/*
possible output:

1 5 1 9 3 4  : 2 initial sorted elements => 1 5
5 1 3 1 4 9  : 1 initial sorted elements => 5
5 4 9 3 1 1  : 1 initial sorted elements => 5
1 9 4 3 1 5  : 2 initial sorted elements => 1 9
5 3 1 1 9 4  : 1 initial sorted elements => 5
1 9 3 5 4 1  : 2 initial sorted elements => 1 9
5 3 1 4 1 9  : 1 initial sorted elements => 5
1 3 5 4 1 9  : 3 initial sorted elements => 1 3 5
1 1 9 5 4 3  : 3 initial sorted elements
5 4 1 1 3 9  : 1 initial sorted elements
9 1 4 3 5 1  : 1 initial sorted elements
5 1 3 4 1 9  : 1 initial sorted elements
1 3 9 4 1 5  : 3 initial sorted elements
1 3 4 1 5 9  : 3 initial sorted elements
4 5 3 1 9 1  : 2 initial sorted elements
3 5 4 1 9 1  : 2 initial sorted elements
1 4 3 9 1 5  : 2 initial sorted elements
1 4 9 3 5 1  : 3 initial sorted elements
1 4 5 1 9 3  : 3 initial sorted elements
3 1 9 1 5 4  : 1 initial sorted elements
3 5 1 1 9 4  : 2 initial sorted elements
1 4 1 9 3 5  : 2 initial sorted elements
4 5 3 9 1 1  : 2 initial sorted elements
9 4 1 5 3 1  : 1 initial sorted elements
9 5 4 1 3 1  : 1 initial sorted elements
3 5 4 1 9 1  : 2 initial sorted elements
1 4 9 3 1 5  : 3 initial sorted elements
1 3 5 9 4 1  : 4 initial sorted elements => 1 3 5 9

Process returned 0 (0x0)   execution time : 0.013 s
*/

