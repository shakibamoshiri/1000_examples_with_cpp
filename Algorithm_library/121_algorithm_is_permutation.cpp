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
/// is_permutation
// Returns true if there exists a permutation of the elements in the range
// [first,last) that makes that range equal to the range [first2,last2).
// Two version of this function use operator == for equality, whereas
// another two version use the binary predicate

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
#include <unistd.h>

template<typename A,typename B>
bool is_permute (A one, B two){
    return std::is_permutation(one.begin(),one.end(),two.begin(),two.end());
}

int main(){

    std::vector<char> one {'a','b','c','d'};
    std::vector<char> two {'a','b','c','d'};

    std::srand(std::time(0)); // to make number randomly

    while( is_permute(one,two) ){ // It always returns true

        for(const char c:one)std::cout<<c<<' ';     // print one
        std::cout<<" < is permutation of > ";
        for(const char c:two)std::cout<<c<<' ';     // print two
        std::cout<<std::endl;                       // print newline for new print of one

        std::random_shuffle(one.begin(),one.end()); // shuffles one
        std::random_shuffle(two.begin(),two.end()); // shuffles two

        // this while will never stop, so I use sleep(1) function to see what happens
        sleep(1);
    }

    // after coming out of the while

return 0;}









