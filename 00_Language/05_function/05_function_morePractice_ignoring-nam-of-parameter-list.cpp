/*
Function:
    declaring function
    default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
    Declaring Function
**********************
    parameter list
syntax:
1   attribute ( optional ) dss declarator
2   attribute ( optional ) dss declarator = initializer
3   attribute ( optional ) dss abstract-declarator (optional)
4   attribute ( optional ) dss abstract-declarator (optional) = initializer
5   ...
6   void


*/

#include <iostream>
#include <string>
#include <array>

void p2f(int (), int ()){
    std::cout<<__func__<<std::endl;
}

void p2f2 (int (*)(), int (*)()){
    std::cout<<__func__<<std::endl;
}

void p2f3 (int (*a)(), int (*b)()){
    std::cout<<__func__<<std::endl;
}

int f(){}
int main(){

    p2f(f,f);
    p2f2(f,f);
    p2f3(f,f);
}










