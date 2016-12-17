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
/// std::function constructor
//
//  Constructs a std::function from a variety of sources.


#include <iostream>
#include <functional>

struct St0 {
    int number;

    St0 (int temp): number( temp ) {}

    void print_add (int temp) const { std::cout << number + temp << '\n'; }

}; // end of structure St0


struct PrintNumber { void operator () (int temp) const { std::cout << temp << '\n'; } }; // end of structure PrintNumber

void print_number (int temp){ std::cout << temp << '\n'; }  // end of function print_number

int main (){

    // stores a free function
    std::function< void (int) > fj_display = print_number;
    fj_display( 10 );

    // stores a lambda function
    std::function< void () > fj_display_33 = [](){ print_number( 33 ); };
    fj_display_33();

    // stores the results of a call to std::bind
    std::function< void () > fj_display_3322 = std::bind( print_number, 3322 );
    fj_display_3322;




    // stores a call to a member function
    std::function< void(const St0&, int) > fj_add_display = &St0::print_add;
    const St0 one(1234);
    fj_add_display (one, 766);

    // stores a call to a member function and object
    using std::placeholders::_1;
    std::function<  void (int) > fj_add_display2
    = std::bind
    ( &St0::print_add,
     St0,
      _1);

    fj_add_display2(20);



}










