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

struct B {
    int get_data( int temp ){ return temp; }
};

struct D : B {};


int main(){
    // pointer to member function

    int ( B::* b_fptr )( int ) = &B::get_data;
    int ( D::* d_fptr )( int ) = &D::get_data;

    D d1;
    B* pb = &d1;

    std::cout << pb->get_data(1) << '\n';           // okay prints 1

    std::cout << (pb->*b_fptr)(2) << '\n';          // okay prints 2

    // error
    // incomplete type object
//    std::cout << (pb->*d_fptr)(3) << '\n';          // okay prints 3
}
/* output:


*/
