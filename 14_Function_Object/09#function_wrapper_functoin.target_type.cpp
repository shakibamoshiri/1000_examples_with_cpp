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
/// std::function target_type
//
//  Returns the type of the stored function.


#include <iostream>
#include <functional>


int func (int temp){ return -temp; }


int main (){

    // note that:
    // both function object have the same type but
    // their target do not.
    std::function< int (int) > fobj1 ( func ),                          // first
                               fobj2 ( [](int temp){ return -temp; } ); // second

    std::cout << fobj1.target_type().name() << std::endl;
    std::cout << fobj2.target_type().name() << std::endl;

}

/* output for me:

PFiiE
Z4mainEUliE_

*/
