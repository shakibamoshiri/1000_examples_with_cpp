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
#include <string>
//#include "../helpful/user_assert"

int main(){
    // default allocator for string
    std::allocator<std::string> al_str;

    // same, but obtained by rebinding from the type of al_str
    decltype(al_str)::rebind<std::string>::other str_1;

    // same, but obtained by rebinding from the type of al_str via allocator_traits
    std::allocator_traits<decltype(al_str)>::rebind_alloc<std::string> str_2;

    // space for two strings
    std::string* sptr = al_str.allocate(2);

    // constructs an object in allocated storage
    al_str.construct(sptr,"how are");
    al_str.construct(sptr + 1, "you today?");

    std::cout << sptr[0] << ' ' << sptr[1] << std::endl;

    // destruct an abject in allocated storage
    al_str.destroy(sptr);
    al_str.destroy(sptr + 1);

    // deallocates storage
    al_str.deallocate(sptr, 2);

}




