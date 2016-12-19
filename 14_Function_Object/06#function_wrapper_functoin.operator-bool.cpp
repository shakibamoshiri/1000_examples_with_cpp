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
/// std::function operator bool
//  explicit operator bool () const
//
//  Checks whether *this stores a callable function target, i.e. is not empty

#include <iostream>
#include <functional>

void print () { printf ("this a test to see how bool operator works\n"); }

int main (){

    std::function< void () > fj1;   // empty
    std::function< void () > fj2( print );  // initializes by using constructor

    if (fj1) std::cout << "okay fj1 took an object\n";
    else     std::cout << "no, fj1 is empty\n";

    if (fj2) std::cout << "okay fj2 took an object\n";
    else     std::cout << "no fj2 is empty\n";

}
/* output for me:

no, fj1 is empty
okay fj2 took an object

*/
