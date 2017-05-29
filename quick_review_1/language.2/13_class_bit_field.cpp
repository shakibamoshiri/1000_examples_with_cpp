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
//  bit filed sets
/******************/
#include <iostream>

struct S {
    // 4 bits unsigned field
    // allowed values are 0..15
    unsigned int bit : 4;
};

int main(){

    std::cout << sizeof ( S ) << '\n';

    S obj{ 7 };     // okay
    std::cout << obj.bit << '\n';   // 7

    obj = { 15 };
    std::cout << obj.bit << '\n';   // 15

    obj = { 16 };       // overflow
    std::cout << obj.bit << '\n';   // 0

}

/* output:

4
7
15
0

*/
