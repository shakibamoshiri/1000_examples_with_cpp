/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Iterator operation:
    advance:                        advances an iterator by giving distance
    distance:                       returns the distance between two iterator
    next:                           increment an iterator
    prev:                           decrement an iterator

*/
/// next
// Return the nth successor or iterator it.
//
// NOTE:
// Although the expression ++c.begin() often complies, it is not guaranteed to do so:
// c.begin() is an r-value expression, and there is no BidirectionalIterator requirement
// that specifies that increment of an r-value is guaranteed to work. In particular, when
// iterator are implemented as pointers, ++c.begin() does not complies, while std::next(s.begin()) does.



#include <iostream>
#include <iterator>
// #include <sstream>

#include <algorithm>
// #include <functional> // std::greater<int>()
#include <vector>
// #include <list>
// #include <set>
// #include <set>
// #include <string>
 // #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>
#include "../helpful/print_container" // operator<< overloaded



int main(){

    std::vector<int> vector{1,2,3,4,5,6};
    std::cout<<*std::begin(vector)<<std::endl;              // okay point to index [0]

    std::cout<<*std::next(std::begin(vector))<<std::endl;   // okay point to index [1]

    std::cout<<*(std::next(std::begin(vector))+1)<<std::endl; // okay point to index [2]



return 0;}






