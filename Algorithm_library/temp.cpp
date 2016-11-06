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
Defined in header <cstdlib>

C Library

    qsort               sorts a range of elements with unspecific type
    bserach             searches an array from an elements of unspecified type

*/
/// bsearch
// Find an element equal to element point to by key in an array pointed to by ptr.
//
// The behavior is undefined if the array is not already partitioned in ascending
// order with respect to key, according to the same criterion that 'comp' uses.
//
// If the array contains several elements that 'comp' would indicate as equal
// to the element searched for, then it is unspecified which element the function
// with return as the result.

#include <iostream>
#include <cstdlib> // for bsearch
#include <algorithm>

// #include <iterator>
// #include <functional> // std::greater<int>()
// #include <vector>
// #include <string>

// #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>
// #include <unistd.h>
// #include <climits>

int compare (const void* ao,const void* bo){

    const int* A = (int*) ao;
    const int* B = (int*) bo;

    if(*A < *B) return -1;
    if(*A > *B) return 1;
    else        return 0;

}


int main(){

    int arr[10]{0};

    // filling arr
    std::iota(std::begin(arr),std::end(arr),1); // 1,2,3,...

    int key = 4;
    int* r1 = (int*) std::bsearch(&key,                         // looking for
                                  arr,                          // array
                                  sizeof(arr)/sizeof(*arr),     // length of array
                                  sizeof(*arr),                 // size of type of array
                                  compare);                     // comparison function

    if(r1)  std::cout<<"value "<<key<<" found at position "<<(r1-arr)<<std::endl;
    else    std::cout<<"value "<<key<<" not found\n";

    key = 11;
    int* r2 = (int*) std::bsearch(&key,                         // looking for
                                  arr,                          // array
                                  sizeof(arr)/sizeof(*arr),     // length of array
                                  sizeof(*arr),                 // size of type of array
                                  compare);                     // comparison function

    if(r2)  std::cout<<"value "<<key<<" found at position "<<(r1-arr)<<std::endl;
    else    std::cout<<"value "<<key<<" not found\n";



return 0;}







