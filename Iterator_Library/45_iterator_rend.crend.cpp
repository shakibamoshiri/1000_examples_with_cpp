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
/// rend and crend
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
// Returns an iterator to the reverse-end of the given container 'c' or array of array



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

    // prints the reit ( end of the vec ) is undefined behavior
    // because it is reverse-end, it should be decrease
    std::cout<<*(--vec.rend()); // first decreases then dereferences

    // also it modifiable
    *--vec.rend()=1000; // change 1 to 1000
    // decreasing and increasing the iterator end and begin is a temporary case
    // so these decrement has no effect
    --vec.rend();   // no effect
    --vec.rend();   // no effect
    --vec.rend();
    --vec.rend();
    --vec.rend();   // no effect
    std::cout<<'\n'<<*(--vec.rend()); // first decreases then dereferences

    // and crend is a constant reverse-end
return 0;}






