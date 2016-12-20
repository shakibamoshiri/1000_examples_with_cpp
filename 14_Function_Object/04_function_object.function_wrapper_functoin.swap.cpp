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
/// std::function swap
//  void swap (function& other);
//
//  Exchanges the stored callable objects of *this and other


#include <iostream>
#include <functional>

void print_int1 (const int temp = 1){ std::cout << "this is print_int1\n"; }

void print_int2 (const int temp = 2){ std::cout << "this is print_int2\n"; }

int main (){

    std::function< void (int) > pi1 = print_int1;
    std::function< void (int) > pi2 = print_int2;

    /// NOTE;
    // default arguments are ignored in the objects of function object
    // and you should enter them.

    pi1(1);  // 1
    pi2(2);  // 2

    pi1.swap( pi2 );
    std::cout << "after swapping ...\n";

    pi1(1);  // 2
    pi2(2);  // 1

}
/* output for me:



*/
