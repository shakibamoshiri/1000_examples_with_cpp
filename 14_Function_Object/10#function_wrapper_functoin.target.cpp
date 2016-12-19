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
/// std::function target
//  template<class T> T* target()
//  template<class T> T* target() const
//
//  Returns a pointer to the stored callable function object.


#include <iostream>
#include <functional>

int one (int, int){ return 1; }
int two (int, int){ return 2; }

void test (std::function< int (int, int) >const & arg){ // it can be like this: const std::function<int(int,int)>&

    std::cout << "test function: ";

    if (arg.target< std::plus<int> >() ) std::cout << "it is plus\n";
    if (arg.target< std::minus<int> >() ) std::cout << "it is mines\n";

    int (*const *fptr)(int,int) = arg.target< int (*)(int,int) >();

    if (fptr && *fptr == one ) std::cout << "it is the function one\n";
    if (fptr && *fptr == two ) std::cout << "it is the function two\n";
}


int main (){

    test( std::function< int (int,int) >( std::minus<int>() ) );
    test( std::function< int (int,int) >( std::plus<int>() ) );

    test( std::function< int (int,int) >( one ) );
    test( std::function< int (int,int) >( two ) );

}

/* output for me:

test function: it is mines
test function: it is plus
test function: it is the function one
test function: it is the function two


*/
