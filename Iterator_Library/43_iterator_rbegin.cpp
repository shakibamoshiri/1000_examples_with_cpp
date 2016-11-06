/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Range access
    Those non-member function provides a generic interface for containers, plain arrays, and std::initializer_list.

    begin:                          returns an iterator to the beginning of a container or array
    cbegin:                         same as begin but constant
    end:                            returns an iterator to the end of a container or array
    cend:                           same as end but constant
    rbegin:                         returns a reverse iterator to a container of array
    crbegin:                        same as rbegin but constant
    rend:                           returns a reverse end iterator to a container of array
    crend:                          same as rend but constant

*/
/// rbegin and crbegin
//  (rend)                                               (rbegin)
//  -------------------------------------------------------------
//  |   | * | * | * | * | * | * | * | * | * | * | * | * | * | * | <-
//  -------------------------------------------------------------
//
//      (begin)                                               (end)
//      -------------------------------------------------------------
//  ->  | * | * | * | * | * | * | * | * | * | * | * | * | * | * |   |
//      -------------------------------------------------------------
//
// Returns an iterator to the reverse-beginning of the given container 'c' or array array.



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
  #include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>
// #include "../helpful/print_container" // operator<< overloaded


int main(){
    std::vector<int> vec{1,2,3,4,5,6,7};
    auto rbit=vec.rbegin();  // points the reverse-beginning of the vec
    auto reit=vec.rend();    // points the reverse-ending of the vec

    while(rbit!=reit)std::cout<<*rbit++<<' '; // 7 6 5 4 3 2 2 1
return 0;}






