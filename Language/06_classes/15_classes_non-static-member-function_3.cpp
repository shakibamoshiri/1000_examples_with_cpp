/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    * non-static member function
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
    non-static member function
    A non static member function is a function that is declared in member
    specification of a class without a 'static' or 'friend' specifier

*/

#include <iostream>
#include <string>
#include <vector>

/// const, volatile, and ref-qualified member function
// A non-static member function can be declared with a
//    - const
//    - volatile
//    - const volatile
//    - &
//    - &&
// A non-static member function can be declared with either an l-value
// ref-qualified ( the character & after the function name ) or r-value
// ref-qualified ( the character && after the function name.(since c++11))

struct C {
    int n;
    void f() &  { std::cout<<"L-value\n";}
    void f() && { std::cout<<"R-value\n";}
};

int main(){
    C c;
    c.f();      // L-value
    C().f();    // R-value
    std::move(c).f();   // R-value
}
