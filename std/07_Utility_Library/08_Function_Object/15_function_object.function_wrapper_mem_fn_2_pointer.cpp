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

    // using pinter to member function instead of std::mem_fn


//    auto greet = std::mem_fn( &People::display_greeting );
//    greet( one );   // it would like one.display_greeting()
    void (People::* fo_ptr)() = &People::display_greeting;
    (one.*fo_ptr)();


//    auto number = std::mem_fn( &People::display_number );
//    number( one, 3 );
    void (People::* fo_ptr2)(int) = &People::display_number;
    (one.*fo_ptr2)(33);

//
//    auto access_date = std::mem_fn( &People::data );
//    std::cout << "data: " << access_date( one ) << '\n';

    int People::* data = &People::data;
    std::cout << "data: " << data << '\n';
}

/* output for me:

hello world.
number: 33
data: 1


*/


