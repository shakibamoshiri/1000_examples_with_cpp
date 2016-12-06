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
/// lexicographical_compare
// Checks if the range [first1,last1) is lexicographically less than
// the second range [first2,last2).
//
// Lexicographical comparison is a operation with the following properties:
// > Two range are compared element by element
// > The first mismatching element defines which range is lexicographically less
//   or greater than the other
// > If one range is a prefix of another, the shorter range is lexicographically
//   less than the other
// > If two range have equivalent elements and are of the same length, then the range
//   lexicographically equal
// > An empty range is lexicographically less than any non-empty range.
// > Two empty ranges are lexicographically equal.
//
// Return Value:
// true if the first range is lexicographically less than second

#include <iostream>
#include <algorithm>
#include <iomanip>

// #include <iterator>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <string>

// #include <array>
// #include <random>
 #include <cstdlib>
 #include <ctime>
// #include <unistd.h>

template<typename A,typename B>
bool lex_com (A one, B two){
    return std::lexicographical_compare(one.begin(),one.end(),two.begin(),two.end());
}

int main(){

    std::vector<char> one {'a','b','c','d'};
    std::vector<char> two {'a','b','c','d'};

    std::srand(std::time(0)); // to make number randomly

    while( !lex_com(one,two) ){ // lex_com is the extra work and no need, but here is used for seeing the short syntax

        for(const char c:one)std::cout<<c<<' ';     // print one
        std::cout<<" >= ";                          // print >=
        for(const char c:two)std::cout<<c<<' ';     // print two
        std::cout<<std::endl;                       // print newline for new print of one

        std::random_shuffle(one.begin(),one.end()); // shuffles one
        std::random_shuffle(two.begin(),two.end()); // shuffles two

    }

    // after coming out of the while
    for(const char c:one)std::cout<<c<<' ';
    std::cout<<" <  ";
    for(const char c:two)std::cout<<c<<' ';
    std::cout<<std::endl;

return 0;}










