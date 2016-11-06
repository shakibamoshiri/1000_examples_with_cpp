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
/// prev ( previous )
// Return the nth predecessor of iterator 'it'.



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
    std::cout<<*(std::end(vector)-1)<<std::endl;              // okay point to index [5] -> 6
    // NOTE:
    // *std::end(vector) is undefined behavior

    std::cout<<*std::prev(std::end(vector))<<std::endl;   // okay point to index [5] -> 6

    std::cout<<*(std::prev(std::end(vector))-1)<<std::endl; // okay point to index [4] -> 5



return 0;}






