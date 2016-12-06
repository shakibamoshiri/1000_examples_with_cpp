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
/// is_heap_until
// Examines the range [first,last) and find the largest beginning at first which is a max heap.
// One version uses operator < to compare elements,
// another uses the given comparison function comp.
//
// Return value:
// The upper bound of the largest range beginning at first which is a max heap.
// That is, the last iterator it for which range [first, it) is a max heap.
//
// NOTE:
// A max heap is a range of elements [first,last) the has the following properties:
// > *first is the largest element in the range
// > a new element can be added using std::push_heap()
// > the first element can be removed using std::pop_heap()

#include <iostream>
#include <algorithm>
#include <iomanip>

#include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
#include <random>
// #include <cstdlib>
// #include <ctime>





int main(){

    std::vector<int> v{3,1,4,1,5,9};

    std::make_heap(v.begin(),v.end());

    // probably mess up the heap
    v.push_back(2);
    v.push_back(6);

    const int* heap_end = &(*std::is_heap_until(v.begin(),v.end()));
    // Of course you can use auto keyword if you are confusing with int*
    auto heap_end_2 = std::is_heap(v.begin(),v.end());

    std::cout<<"All of v:\t";
    for(const int i:v)std::cout<<i<<' ';
    std::cout<<'\n';

    std::cout<<"Only heap of v:\t";
    const int* bv=&(*std::begin(v));
    // Of course you can use for_range if you are confusing with this form of while that I have written
    while(bv != heap_end)std::cout<<*bv++<<' ';

return 0;}










