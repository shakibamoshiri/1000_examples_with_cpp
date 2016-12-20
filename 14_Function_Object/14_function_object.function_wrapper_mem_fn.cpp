/*
            Function Object
            ***************

1. Polymorphic Function Wrapper
    1.1 function
    ---------------------------
    1.2 mem_fn
        Function template std::mem_fn generates wrapper objects for pointers to members,
        which can store, copy, and invoke a pointer to member. Both reference and pointer
        (including smart pointers) to an object cab be used when invoking a std::mem_fn.
        for more detail see the man website.

        member type:
            result_type
            argument_type
            first_argument_type
            second_argument_type



*/
///  std::mem_fun

#include <iostream>
#include <functional>

/// Example
//  Use mem_fn to store and execute a member function and a member object

struct People {
    int data = 1;

    void display_greeting () { std::cout << "hello world.\n"; }
    void display_number (int temp){ std::cout << "number: " << temp << '\n'; }
};


int main (){
    People one;

    auto greet = std::mem_fn( &People::display_greeting );
    greet( one );   // it would like one.display_greeting()

    auto number = std::mem_fn( &People::display_number );
    number( one, 3 );

    auto access_date = std::mem_fn( &People::data );
    std::cout << "data: " << access_date( one ) << '\n';
}

/* output for me:
hello world.
number: 3
data: 1
*/
