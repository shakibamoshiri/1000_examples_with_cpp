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
#include <vector>
#include <iterator>
#include <numeric>




/// copy
/// copy_if             copies a range of elements to a new location
// Copies the elements in the range, defined by [first, last) to
// another range beginning at d_first. Something like this:
// std::copy ( input first, input last, output first)


int main(){
    std::vector<int> vi(10);
    std::iota(vi.begin(),vi.end(),0);   // put 0 to 9 in the vi

    std::vector<int> vi2;
    std::vector<int>::iterator itvi = vi2.begin();

    // Some of ERRORs
    // std::copy_if(vi.begin(), vi.end(), vi2, [](const int i){return i%2;});
    // no match to operator*

    // std::copy_if(vi.begin(), vi.end(), vi2.begin(), [](const int i){return i%2;});
    // segmentation fault

    // std::copy_if(vi.begin(), vi.end(), itvi, [](const int i){return i%2;});
    // with the iterator itvi stiil output is
    // segmentation fault
    // why?
    // because the vi2 has no member. I am not sure, but I think the empty container
    // is always assigns to null
    // if you create:
    // std::vector<int> vi2(5), it works fine.


    // So here we use std::back_iterator to fill the empty container
    std::copy_if(vi.begin(), vi.end(), std::back_inserter(vi2), [](const int i){return i%2!=0;}); // or i%2;

    std::cout<<"vi2: ";
    for (const int t : vi2) std::cout<<t<<' ';
    std::cout<<std::endl;

    std::vector<int> vi3(5);
    // not need to use std::back_inserter
    std::copy_if(vi.begin(), vi.end(), vi3.begin(), [](const int i){return i%2==0;});
    std::cout<<"vi3: ";
    for (const int t : vi3) std::cout<<t<<' ';

    /** implementation:

    for (; __first != __last; ++__first)
        if (__pred(*__first))               // the lambda expression is inserted here
        {
            *__result = *__first;
            ++__result;
        }
        return __result;
    }
    **/
}

