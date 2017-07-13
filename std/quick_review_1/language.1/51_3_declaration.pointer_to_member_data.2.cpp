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

struct Base { int m; };
struct Derived : Base {};

int main(){
    // pointer to data member

    //
    int Base::* p2base = &Base::m;
    int Derived::* p2derived = &Derived::m;

    Derived d1;
    d1.m = 3;

    std::cout << d1.*p2base << ' '<< d1.*p2derived << '\n'; // 3 3

    // but code below is an error
    Base b1;
    std::cout << b1.*p2base << ' '<< b1.*p2derived << '\n';




}
/* output:


*/
