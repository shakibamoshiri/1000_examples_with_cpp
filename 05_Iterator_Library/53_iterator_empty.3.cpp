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



int main(){

    std::vector<int> vec(1,1);
    std::cout<<vec.empty()<<std::endl;  // false

    vec.clear();
    std::cout<<vec.empty()<<std::endl;  //true

return 0;}






