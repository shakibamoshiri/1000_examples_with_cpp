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
/// std::function operator () parenthesis
//  R operator () (ArgTypes... args) const;      // R is result_type

//  invoke the stored callable function target with the parameters 'args'.

// return value:
// None if R is void. Otherwise the return value of invocation of stored callable object.


#include <iostream>
#include <functional>

void call (std::function< int () > fobj){    // can be passed by value
    std::cout << fobj() << '\n';
}

int normal_function (){ return 33; }

int main (){

    int number = 22;

    std::function< int () > fobj = [&number](){ return number; };

    call (fobj);    // passes the object to call function
                    // 22

    number = 44;
    call (fobj);    // 44

    fobj = normal_function;
    call (fobj);    // call the normal_function through call function
                    // 33

}
/* output for me:



*/
