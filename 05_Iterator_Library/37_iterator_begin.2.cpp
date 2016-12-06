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
#include <array>
// #include <list>
// #include <random> // for using of std::random_device and std::mt19937
// #include <cstdlib>
// #include <ctime>

// #include <unistd.h>
// #include <climits>
#include "../helpful/print_container" // operator<< overloaded


// non-const-qualified iterator
template<typename C>
typename C::iterator mybegin ( C& c){ return c.begin(); }

// const-qualified iterator
template<typename C>
typename C::const_iterator mybegin2(const C& c){return c.begin();}
int main(){

    std::vector<int> vector{1,2,3,4,5,6};
    std::cout<<*mybegin(vector)<<std::endl;     // 1
    std::cout<<*mybegin2(vector)<<std::endl;    // 1

    std::string str("How are you today?");
    std::cout<<*mybegin(str)<<std::endl;
    std::cout<<*mybegin2(str)<<std::endl;

    std::array<int,3> array{11,12,13};
    std::cout<<*mybegin(array)<<std::endl;
    std::cout<<*mybegin2(array)<<std::endl;

    // note:
    // const-qualified and non-const-qualified both have overloaded
    // as the same name: begin
    // and also for array C-type

return 0;}

/*
complier ERROE message when you try to use non-const-iterator for const_iterator object

like typename C::iterator mybegin(const C& c)

could not convert ‘(& c)->std::vector<_Tp, _Alloc>::begin<int, std::allocator<int> >()
’ from ‘std::vector<int>::const_iterator {aka __gnu_cxx::__normal_iterator<const int*,
std::vector<int> >}’ to ‘std::vector<int>::iterator {aka __gnu_cxx::__normal_iterator<int*, std::vector<int> >}’|
*/



