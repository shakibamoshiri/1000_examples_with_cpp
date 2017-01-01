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
///  operator == ,!= (std::function)
//
//  Compares a std::function with a null pointer.
//  Empty functions (that is, function without a callable target)
//  compare equal, non-empty function compare non-equal.


#include <iostream>
#include <functional>

using SomeVoid = std::function< void (int) >;

class C {
private:
    SomeVoid void_func;

public:
    C( SomeVoid tempfunc = nullptr ) : void_func( tempfunc ){
        if( void_func == nullptr )
            void_func = std::bind( &C::default_func, this, std::placeholders::_1 );  // end of if statement

        void_func( 7 );
    }

    void default_func (int temp){ std::cout << temp << '\n'; }
};

void user_func (int temp){ std::cout << (temp + 1) << '\n'; }

int main (){

    C c1;

    C c2(user_func);

}

/* output for me:

7
8


*/
