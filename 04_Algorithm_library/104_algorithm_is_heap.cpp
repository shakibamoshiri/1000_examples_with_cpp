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
/// is_heap
// Checks if the elements in range [first,last) are a max heap
// One version uses operator < to compare elements,
// another uses the given comparison function comp.
//
// Return value:
// true if the range is max heap, false otherwise
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

    std::vector<int> v1{0,2,34,3,4,9,10};


    std::cout<<std::boolalpha<<std::is_heap(v1.begin(),v1.end())<<std::endl;
    std::make_heap(v1.begin(),v1.end()); // push the largest element in the beginning
    std::cout<<std::boolalpha<<std::is_heap(v1.begin(),v1.end())<<std::endl;

    for(const int i:v1)std::cout<<i<<' ';
    std::cout<<'\n';

    std::vector<int> v2{0,2,34,3,4,9,10};

    // Is v2 heap?
    std::sort(v2.begin(),v2.end());
    if(std::is_heap(v2.begin(),v2.end())) std::cout<<"After sorting, okay, v2 is heap\n";
    else                                  std::cout<<"After sorting, no, v2 is not heap\n";

    // Is v2 heap?
    std::reverse(v2.begin(),v2.end()); // goes the largest element in the beginning
    if(std::is_heap(v2.begin(),v2.end())) std::cout<<"After revering, okay, v2 is heap\n";


return 0;}










