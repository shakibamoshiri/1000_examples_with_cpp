/*
        Dynamic Memory Management
        *************************

Allocators:
Allocators are class template encapsulating memory allocating strategy.
This allows generic containers to decouple memory management from the data itself.

    > allocator                     the default allocator
    > allocator_traits              provides information about allocator types
    > allocator_arg_t               tag type used to select allocator-aware constructor overloads
    > allocator_arg                 an object of type std::allocator_arg_t used to select allocator-aware
    > uses_allocator                checks if the specified type supports uses-allocator construction
    (in header file: <scoped_allocator>)
    > scoped_allocator_adapter      implements multi-level allocator for multi-level containers

*/
/// std::allocator
// The std::allocator class template is the default Allocator used by
// all standard library containers if no user-specified allocator is
// provide. The default allocator is stateless, that is, all instances of
// the given allocator are interchangeable, compare equal and can
// deallocate memory allocated by any other instance of the same allocator type.
//
/// member type:
// value type       T
// pointer          T*
// const_pointer    const T*
// reference        T&
// const_reference  const T&
// size_type        std::size_t
// different_type   std::ptrdiff_t
//
/// Member function
// constructor
// destructor
// address
// allocate
// deallocate
// max_size
// construct
// destroy
// operator ==
// operator !=


#include <iostream>
#include <memory>
#include <algorithm>
//#include "../helpful/user_assert"

int main(){
    std::allocator<int> alloc1;     // default allocator for int
    int* p = alloc1.allocate(10);   // space for 10 ints | array of int

    p[1] = 1;
    p[9] = 9;

    std::cout << p[1] << ' ' << p[2] << ' ' << p[9]<< std::endl; // 1   0   9

    alloc1.deallocate(p,10);
}




