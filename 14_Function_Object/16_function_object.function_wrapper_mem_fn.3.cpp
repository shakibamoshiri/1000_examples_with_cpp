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

/// Example 2
//  Demonstrates the effect of the C++14 changes to the
//  specification of std::mem_fn


struct X {
    int x;

    int& easy (){ return x; }
    int& get () { return x; }
    const int& get () const { return x; }
};

int main (){

    auto one = std::mem_fn( &X::easy );     // no problem at all

//    auto two = std::mem_fn< int& >( &X::get );  // no longer works in C++14

    auto three = std::mem_fn< int& () >( &X::get ); // works with both C++11 and 14

    auto four = []( X x ){ return x.get(); };   // another approach to overload resolution

    X x = {23}; // or x{23};

    std::cout << "one( x )\t"   << one( x ) << '\n';
    std::cout << "three( x )\t" << three( x ) << '\n';
    std::cout << "four( x )\t"  << four( x ) << '\n';

    one( x ) = 543;
    std::cout << "\none( x )\t"   << one( x ) << '\n';

    three( x ) = 234;
    std::cout << "three( x )\t" << three( x ) << '\n';
    std::cout << "four( x )\t"  << four( x ) << '\n';

}

/* output for me:

one( x )        23
three( x )      23
four( x )       23

one( x )        543
three( x )      234
four( x )       234
*/


