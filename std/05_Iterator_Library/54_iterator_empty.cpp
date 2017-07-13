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
/// date
// Returns a pointer to the block of memory containing the elements of the container.



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

template<typename T,unsigned int N>
const T* data(const T(&arr)[N])noexcept{return arr;}

int main(){

    int arr[]={2,3,4,5,6};
    std::cout<<data(arr)<<std::endl;    // address of arr
    std::cout<<*data(arr)<<std::endl;   // value of first element

    // It looks like std::begin()
    std::cout<<std::begin(arr)<<std::endl;

return 0;}






