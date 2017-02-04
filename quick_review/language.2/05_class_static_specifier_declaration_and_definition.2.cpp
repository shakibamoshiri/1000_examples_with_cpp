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
//  static specifier

#include <iostream>

struct B;   // forward declaration

struct A {

    static int si[];        // declaration, and incomplete type
    static B sb_ojb;        // declaration, and incomplete type
    static A sa_obj;        // declaration, and incomplete type (inside its own definition)

};

int A::si[ 10 ];            // definition, complete type

struct B {};
B A::sb_ojb;                // definition, complete type

A A::sa_obj;                // definition, complete type


int main(){



}

/* output:



*/
