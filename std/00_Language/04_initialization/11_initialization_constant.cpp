/*
Initialization:
    value       initialization
    copy        initialization
    direct      initialization
    aggregate   initialization
    list        initialization
    reference   initialization
    zero        initialization
    constant    initialization
********************************
Constant Initialization
Sets the initial values of the static constant

Syntax:
static T& reference = constant-expression
static T object     = constant-expression

*/

#include <iostream>
#include <string>
#include <array>

struct S {
    static const int c;
};

const int d = 10*S::c;      // not a constant expression: S::s has no preceding
                            // initializer, this initialization happens after const
const int S::c = 5;

int main(){

    std::cout<<"d = "<<d<<std::endl;
    std::array<int, S::c> arr;  // okay, S::s in a constant expression
//    std::array<int, d> arr2;    // error, d is not a constant expression
}










