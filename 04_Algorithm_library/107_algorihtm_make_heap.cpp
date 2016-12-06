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
/// make_heap
// Constructs a max heap in the range [first,last)
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

#include <iterator>
#include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
#include <random>
// #include <cstdlib>
// #include <ctime>





int main(){

    std::vector<int> v{0,1,4,1,5,9,3};

    int front = v.front();  // 0 in the front
    int back =  v.back();   // 2 in the back
    std::cout<<"Beginning of the v: ["<<front<<"] and ending of the v: ["<<back<<"]\n";

    std::make_heap(v.begin(),v.end()); // now, the largest element in the front

    std::cout<<"After make_heap(v):\t";
    for(auto i:v)std::cout<<i<<' ';


    std::pop_heap(v.begin(),v.end()); // now, the largest element in the back
    front = v.front();
    back =  v.back();
    std::cout<<"\nBeginning of the v: ["<<front<<"] and ending of the v: ["<<back<<']';
    std::cout<<"\nAfter pop_heap(v):\t";
    for(auto i:v)std::cout<<i<<' ';
    v.pop_back();   // now, remove the 9 form the end of v

    std::cout<<"\nAfter removing the largest element:\t";
    for(auto i:v)std::cout<<i<<' ';

return 0;}










