/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// class
//  constant static member
//  static const data member can be initialized inside the class definition
//  non-constant does not allow

#include <iostream>

struct S {
    // static int si = 10; // error
    // error: ISO C++ forbids in-class initialization of non-const static member ‘S::si’
};

struct D {
    const static int si = 10;       // okay
    const static int si2 { 20 };    // okay, since c++11
    constexpr static int csi = 30;  // okay
};

int main(){

    std::cout << D::si << '\n';
    std::cout << D::si2 << '\n';
    std::cout << D::csi << '\n';

}

/* output:

10
20
30

*/
