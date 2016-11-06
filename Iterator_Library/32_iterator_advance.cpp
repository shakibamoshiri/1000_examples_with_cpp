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
/// advance
// Increment the given iterator 'it' by 'n' element
//
// Return value: none

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

    std::vector<int> vector{1,2,3,4,5,6,7};

    std::vector<int>::iterator viter=std::begin(vector);
    std::vector<int>::iterator titer=viter; // temporary
    std::advance(viter,3);

    titer+=3;
    std::cout<<*viter<<std::endl;       // point to index 3
    std::cout<<vector[3]<<std::endl;    // point to index 3
    std::cout<<*titer<<std::endl;       // point to index 3

return 0;}






