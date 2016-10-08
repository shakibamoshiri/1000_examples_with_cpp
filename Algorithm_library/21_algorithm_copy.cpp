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
//
//
// Note:
// When copying overlapping range, std::copy is appropriate when copying
// to the left (beginning of the destination range is outside the source range)
// while std::copy_backward is appropriate when copying to the right (end of the
// destination range is outside the source range ).

int main(){

    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(),from_vector.end(),0);     // puts 0 to 9 into the from_vector
    for ( const int t : from_vector)    std::cout<<t<<' ';
    std::cout<<std::endl;

    std::vector<int> to_vector;
    std::copy(from_vector.begin(),from_vector.end(),std::back_inserter(to_vector));
    // The std::back_inserter is a member of iterator library which put the given value
    // at the end of a container. Because to_vector is empty, back_inserter
    // put the first value at the first and the second at the second and so on.
    // It is a convenience function template that constructs a std::back_insert_iterator

    // other alternatively
    // std::vector<int> to_vector(from_vector.size());
    // std::copy (from_vector.being(), from_vector.end(), to_vector.begin());

    // either was is equivalent to
    // std::vector<int> to_vector = from_vector;

    std::cout<<"to_vector containers: ";
    std::copy(to_vector.begin(),to_vector.end(),std::ostream_iterator<int>(std::cout," "));


}

