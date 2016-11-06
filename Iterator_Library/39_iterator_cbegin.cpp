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
/// begin
// Is assumed C is container and c is the object of C
//
// Return an iterator to the beginning of the given container 'c' or array array.
// these template rely on C::begin() having a responsible implementation.
// 1)   Returns exactly c.begin(), which is typically an iterator to the beginning
//      of the sequence represented by c. If C is a standard Container, this return
//      C::iterator when c is not const-qualified, and C::const_iterator otherwise.
// 2)   Returns a pointer to the beginning of the array.
// 3)   Returns exactly std::begin(c), with c always treated as const-qualified. If
//      is a standard Container, this always return C::const_iterator.
//
// So c.begin() returns C::iterator
//    std::begin(c) returns C::const_iterator



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

    // cbegin is a const iterator that cannot be modified
    std::vector<short> man {1,2,3,4,5};

    std::cout<<*std::cbegin(man)<<std::endl;    // okay prints 1
    std::cout<<*++std::cbegin(man)<<std::endl;  // okay prints 2

    /// ERROR
    /// for
    *std::cbegin(man)=10;
    /// compliers says
    /// error: assignment of read-only location
    // ‘std::cbegin<std::vector<short int> >(man).__gnu_cxx::__normal_iterator<_Iterator, _Container>::operator*<const short int*, std::vector<short int> >()’

return 0;}






