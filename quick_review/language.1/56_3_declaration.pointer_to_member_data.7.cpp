/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
// #include <string>
// #include <iomanip>

struct S {
    int data;
    const int S::* const p2d;
};

int main(){
    // pointer to data member


    S s { 3, &S::data };    // initials data and p2d

    // regular const pointer to a const pointer-to-member
    const int S::* const * p2p2d = &s.p2d;
    std::cout << s.data << ' ' << s.**p2p2d << '\n';    // okay 3   3




}
/* output:


*/
