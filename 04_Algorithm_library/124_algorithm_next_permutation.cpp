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

Maximum / Minimum Operation

    max                 returns the greater of the given value
    max_element         returns the largest element in a range
    min                 returns the smaller of the given value
    min_element         returns the smallest element in a range
    minmax              returns the larger and the smaller of two elements
    minmax_element      returns the smallest and the largest elements in a range
    lexicographical_compare         returns true if one range is lexicographically less than another
    is_permutation      determines if a sequence is a permutation of another sequence
    next_permutation    generates the next larger lexicographic permutation of a range of elements
    prev_permutation    generates the next smaller lexicographic permutation of a range of elements

*/
/// next_permutation
// Transforms the range [first,last) into next permutation from the
// set of all permutation that are lexicographically ordered with
// respect to operator < or comp.
// Returns true if such permutation exists, otherwise transforms the
// range into the first permutation ( as if by std::sort(first,last)) and return false.
//
// Return Value:
// true if the new permutation is lexicographically greater than the old.
// false if the last permutation was reached and the range was reset to the
// first permutation.

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

    std::string one("abc");     // We assume we have a , b , c

    short count=0;
    do {
        std::cout<<++count<<" : ";
        for(const char c:one)std::cout<<c<<' ';
        std::cout<<std::endl;
        } while(std::next_permutation(one.begin(),one.end()));

    // note:
    // std::next_permutation is done by reference
    std::cout<<"------------------"<<std::endl;
    std::next_permutation(one.begin(),one.end());
    std::cout<<"After one doing std::next_permutation, one is:\t"<<one<<std::endl;

return 0;}









