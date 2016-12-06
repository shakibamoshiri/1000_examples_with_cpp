/*
Classes
    - class declaration
    - union declaration
    * non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    non-static member data

*/

#include <iostream>
#include <string>
#include <vector>

/// Member initialization
// reference member can not be bound (bind) to temporaries in a default member initializer
struct A {
    A() = default;      // okay
    A(int t): r(t) {}   // okay
    const int& r=32;    // okay
};
A one;      // error, ill-formed binding of temporary to reference
A two(23);  // okay, default member initializer ignored because r appears in a constructor
            // however, two.r is a dangling reference


struct B {
    B() = default;
    B(int t): r(t) {}
    const int r = 32;
};
B three;
B four(20);


int main(){
    std::cout<<one.r<<std::endl;    // unknown
    std::cout<<two.r<<std::endl;    // unknown

    std::cout<<std::string(10,'_')<<std::endl;

    std::cout<<three.r<<std::endl;  // okay
    std::cout<<four.r<<std::endl;   // okay
}
