/*
            Function Object
            ***************

1. Polymorphic Function Wrapper
    1.1 function:
        Class template std::function is a general-purpose polymorphic function wrapper.
        Instances of std::function can store, copy, and invoke any Callable target - function,
        lambda expression, bind expression, or other function objects, as well as pointer
        to member function and pointer to member data.
        The stored callable object is called the target of std::function. If a std::function
        contains no target, it is called empty invoking the target of an empty std::function
        result in std::bad_function_call exception begin thrown.
        std::function satisfies the requirement of CopyConstructible and CopyAssignable.

        member type:
            result_type
            argument_type
            first_argument_type
            second_argument_type

        member function:
            constructor
            destructor
            operator =
            swap
            assign
            operator bool
            operator () parenthesis

        target access:
            target_type
            target

        non-member function
            std::swap ( std::function )
            operator == , !=

        helper class
            std::uses_allocator< std::function >
*/
/// std::function assign
//  template<class F, class Alloc>
//  void assign (F&& f, const Alloc alloc);
//
//  Initializes the target with 'f'.
//  alloc is used to allocate  memory for any internal data
//  structures that the function might use.
//  Equivalent to function( allocator_arg, alloc, std::forward< F >.swap( *this )


#include <iostream>
#include <functional>



int main (){

 has not example
}
/* output for me:



*/
