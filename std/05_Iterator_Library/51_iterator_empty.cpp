/*
            The Iterator Library
            ********************
For more detail you can see:
    stl_iterator_base_types.h
    stl_iterator.h
    type_traits
-------------------------------------------------
Container access
    Those non-member function provides a generic interface for containers, plain arrays, and std::initializer_list.

    size:                           returns the size of a container or array
    empty:                          checks whether the container is empty
    data:                           obtains the pointer to the underlying array

*/
/// empty
// Returns whether the given container is empty (since c++17)



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


template<typename T,std::size_t N>
constexpr bool empty(const T(&arr)[N]){return false;} // by default is false because cannot declare an empty array

int main(){
    int arr[]={2,4,6,8,10};
    empty(arr) ? std::cout<<"arr is empty\n" : std::cout<<"Not empty\n";

    /// ERROR
    int arr2[]; // cannot create an array that would be empty
    //             so always they are not empty
    //             and the return value of the function is always false

return 0;}






