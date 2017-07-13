///
/// Expression
///

/**

**/
#include <iostream>
#include <string>
#include <cstdio>
/// user defined
//#include "temp.h"

struct S {
    int f1(double d ){
        printf("%f \n", d); /// variable argument function call.
    }
    int f2(){
        f1(7); /// member function call, same as this->f1()
                /// integer argument converted to double.
    }
};
void f(){
    puts("function called"); // function call
}
int main(){
    f(); /// function call
    S s;
    s.f2(); /// member function call
}

