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
/// std::end and std::cend
// C = container
// c = object of C
//
// Returns an iterator to the end (i.e the element after the last element. that it
// is called past-the-end) of the given container 'c' or array array. These template
// rely on C::end() having a responsible implementation.
//
// 1)   Returns exactly c.end() which is typically an iterator one past the end of the
//      sequence represented by c. If C is a standard 'Container', this returns a
//      C::iterator when c is is not const-qualified, and c C::const_iterator otherwise.
//      (it means for const C& c the return type is: C::const_iterator
// 2)   Returns a pointer to the of the array array.
// 3)   Returns exactly std::end(c), with c always treated as const-qualified. If C is
//      a standard 'Container', this always returns a C::const_iterator.



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
// #include "../helpful/print_container" // operator<< overloaded


int main(){

   std::vector<int> vector{12,24,36,48,60};

   std::find(vector.begin(),vector.end(),36)!=std::end(vector) // using this syntax: returned-boolean-expression ? does-for-true : does-for-false
             ? std::cout<<"okay found\n"
             : std::cout<<"Sorry not found\n";

    // like Perl one-liner :)
    std::find(std::begin(vector),std::end(vector),72)!=std::end(vector)?std::cout<<"okay found\n":std::cout<<"Sorry not found\n";
    // Until it is != end of the vector does search for 72

return 0;}






