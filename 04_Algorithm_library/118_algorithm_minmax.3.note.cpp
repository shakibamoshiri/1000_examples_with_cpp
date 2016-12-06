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
/// minmax
// Returns the lowest and the greatest of the given values
// implementation 1,2 ) returns reference to the smaller and greater of a and b
// implementation 3,4 ) returns the smallest and greatest of the value in initializer_list object

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

    /// NOTE:
    // If one of the parameter is an r-value, the reference returned becomes a
    // dangling reference at the end of the full expression that contain the call
    // to minmax

    int n=10;
    // n/2 => an r-value, and it has no reference

    std::pair<const int&,const int&> result = std::minmax(n/2,n);   // n/2 in the result.first that it means min is a dangling

    std::cout<<"Min:\t"<<result.first<<"\tMax:\t"<<result.second<<std::endl;

    // also
    std::pair<const int&,const int&> result2 = std::minmax(n,n*2);   // n*2 in the result.second that it means mix is a dangling

    std::cout<<"Min:\t"<<result2.first<<"\tMax:\t"<<result2.second<<std::endl;

    std::cout<<"Min 0 and Max 0 are dangling\n";

return 0;}










