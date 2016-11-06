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
/// distance
// Return the number of element between first and last.
//
// The behavior is not reachable from firs by (possibly repeatedly)increment first.



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
    std::cout<<std::distance(vector.begin(),vector.begin()+1)<<std::endl;   // 1
    std::cout<<std::distance(vector.begin(),vector.begin()+2)<<std::endl;   // 2
    std::cout<<std::distance(vector.begin(),vector.begin()+3)<<std::endl;   // 3

    std::cout<<std::distance(vector.begin(),vector.end())<<std::endl;       // 6
    std::cout<<vector.size()<<std::endl;                                    // 6

return 0;}






