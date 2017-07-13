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
/// qsort
// Sorts the given array pointed to by ptr in ascending order.
// The array contains count element of size bytes. Function to
// by comp is used for object comparison.
// If 'comp' indicates two elements as equivalent, their order is undefined


#include <iostream>
#include <cstdlib> // for qsort
#include <iomanip>

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
#include <climits>

int main(){

    int arr[]{-3,34,44,INT_MIN,1,1,4};

    constexpr std::size_t size = sizeof(arr)/sizeof(*arr);  // or sizeof(a)/sizeof(int)

    std::qsort(arr,         // array
               size,        // length of array
               sizeof(int), // size of each element
               [](const void* a,const void* b){     // comparison function

               int arg1=*static_cast<const int*>(a);
               int arg2=*static_cast<const int*>(b);

               if(arg1 < arg2) return -1;
               if(arg1 > arg2) return 1;
               return 0;

               // return (arg1 > arg2) - (arg2 < arg2); possible shortcut
               // return arg1 -arg2;                    erroneous ( fails if INT_MIN is present )
               }); // end of lambda expression


    for ( const int i:arr) std::cout<<i<<' ';
return 0;}







