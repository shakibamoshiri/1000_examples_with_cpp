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
#include <iostream>
//
//class A {
//    // ... other codes
//    B object;   // error, B does not name a type, why? because A does not knew the B what it is, so we should use froward declaration
//};
//class B {};
//

/****************************/

struct B;

struct A {
    B f();
    B object;   // gives the error field ‘object’ has incomplete type ‘B’
                // why I do not know!!!
};

struct B {};

int main(){


}

/* output:



*/
