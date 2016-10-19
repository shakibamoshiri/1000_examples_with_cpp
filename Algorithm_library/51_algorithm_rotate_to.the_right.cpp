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

Modifying sequence operation
    copy
    copy_if             copies a range of elements to a new location
    copy_n              copies a number of elements to a new location
    copy_backward       copies a range of elements in backward order
    move                moves a range of elements to a new location
    move_backward       moves a range of elements to a new location in backward order
    fill                assigns a range of elements a certain value
    fill_n              assigns a value to a number of elements
    transform           applies a function to a range of elements
    generate            saves the result of a function in a range
    generate_n          saves the result of N applications of a function
    remove
    remove_if           removes elements satisfying specific criteria
    remove_copy
    remove_copy_if      copies a range of elements omitting those that satisfy specific criteria
    replace
    replace_if          replaces all value satisfying specific criteria with another value
    replace_copy
    replace_copy_if     copies a range, replacing elements satisfying specific criteria with another value
    swap                swaps the value of two objects
    swap_range          swaps the two range of elements
    iter_swap           swaps the elements pointed to by two iterator
    reverse             reverses the order of elements in a ragne
    reverse_copy        creates a copy of a range that is reversed

    rotate              rotate the order of elements in a range
    rotate_copy         copies and rotate a range of elements

    shuffle
    random_shuffle      randomly re-orders elements in a range
    (until c++ 17)(c++11)
    unique              removes consecutive duplicate element in a range
    unique_copy         creates a copy a of some range of elements that contains no consecutive duplicate
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>




/// rotate          Rotates the order of elements in a range
// Performs a left rotation on a range of elements.
// Specifically, std::rotate swaps the elements in the range [fist, last)
// in such a way that the element n_first becomes the first elements of the
// new range and n_first - 1 becomes the last element.
// A precondition of this function is that [first, n_first) and [n_first, last)
// are valid ranges.
//
//
// std::rotate is a common building block in many algorithms.
// This example demonstrates insertion sort:
int main(){
    std::vector<int> vec{2,4,3,0,5,10,7,3,7,1};
    std::cout<<"Before rotate:\t";        for(const int i : vec) std::cout<<i<<' ';

    // simple rotation to the right
    std::rotate(std::rbegin(vec),std::rbegin(vec)+3, std::rend(vec));
    // It moves 3 element form the beginning to the right
    // and 3 elements form the end adds to the beginning
    // 2 4 3 0 ... 3 7 1
    // becomes
    // 3 7 1 2 4 3 ... 5 10 7


    std::cout<<"\nAfter rotate:\t";       for(const int i : vec) std::cout<<i<<' ';
}














