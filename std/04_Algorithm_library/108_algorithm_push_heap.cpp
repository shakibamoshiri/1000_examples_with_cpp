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

Heap Operation

    is_heap             checks if the given range is a max heap
    is_heap_until       finds the largest subrange that is a max heap
    make_heap           creates a max heap out of a range of elements
    push_heap           adds an elements to a max heap
    pop_heap            removes the largest elements form a max heap
    sort_heap           turns a max heap into a range of elements sorted in according order

*/
/// push_heap
// Insert the element at the position last-1 into the max defined by the range [first,last-1).
// One version uses operator < to compare elements,
// another uses the given comparison function comp.
//
// Return value:
// None.
//
// NOTE:
// A max heap is a range of elements [first,last) the has the following properties:
// > *first is the largest element in the range
// > a new element can be added using std::push_heap()
// > the first element can be removed using std::pop_heap()

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

    std::vector<int> vec{3,5,9,1,0};

    // puts the largest element in front of all
    std::make_heap(vec.begin(),vec.end());

    // now vec contains: 9, ... and so on
    vec.push_back(10);
    // now vec contains: 9, ..., 10 in back of all

    std::push_heap(vec.begin(),vec.end());
    // now because 10 is the largest element, it goes to front of all
    for(const int i:vec)std::cout<<i<<' ';
    // now vec contains: 10, ... and so on



return 0;}










