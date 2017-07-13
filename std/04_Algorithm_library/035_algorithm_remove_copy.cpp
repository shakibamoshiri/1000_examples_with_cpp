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
#include <cstdlib>
#include <string>
#include <iterator> // need for ostream_iterator

/// remove_copy
/// remove_copy_if      copies a range of elements omitting those that satisfy specific criteria
// Copies elements form the range [first, last), to another range beginning
// at the d_first (see implementation in the main site) omitting the elements
// which satisfy specific criteria. ( omit: it means: leave out, not include something and someone)
//
// The remove_copy version, ignore the elements that are equal to value
// the remove_copy_if version, ignores the elements for which predicate p
// return true.
// Source and destination ranges cannot overlap.




int main(){
    std::string str("Text with some    spaces");
    std::cout<<"str:\t"<<str<<std::endl;

    std::string rem;

    std::remove_copy(str.begin(), str.end(), std::back_inserter(rem), ' ');
    std::cout<<"calls the std::remove_copy()"<<std::endl;
    std::cout<<"str:\t"<<str<<std::endl;
    std::cout<<"rem\t"<<rem<<std::endl;
    // As you can see it copy the result of removing into rem string
    // So you can put it to STOUT

    // error, because:
    // basic_ostream(const basic_ostream&) = delete;
    // in the implementation
    //
    // std::remove_copy(str.begin(), str.end(), std::cout,' ');

    // but it is correct with ostream_iterator
    // with #include <iterator> library.
    std::remove_copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout),' ');

}

