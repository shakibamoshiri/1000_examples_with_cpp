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
/// std::function operator =
//
//  Assigns a new target to std::function.
//  there are copy assignment, move assignment and copy form std::reference_wrapper are allowed.


#include <iostream>
#include <functional>

void print_number (const int temp){ printf("you passed here a number: %d\n", temp); }

int main (){

    std::function< void (int) > pn = print_number;
    pn( 22 ); // you passed here a number: 22

    std::function< void (int) > clone_pn = pn;
    clone_pn( 33 );

    std::function< void (int) > move_pn = std::move(pn); // after this assignment pn in destroyed
    move_pn( 44 );

    // this object is destroyed
    pn( 1 );
    // terminate called after throwing an instance of 'std::bad_function_call'
    // what():  bad_function_call
    // Aborted (core dumped)

}
/* output for me:


you passed here a number: 22
you passed here a number: 33
you passed here a number: 44

terminate called after throwing an instance of 'std::bad_function_call'
  what():  bad_function_call
Aborted (core dumped)

*/
