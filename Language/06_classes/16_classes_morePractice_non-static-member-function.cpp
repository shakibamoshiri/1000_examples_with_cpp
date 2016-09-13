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
    C(int t): n(t) {}
    void f() &  { std::cout<<"L-value and n = "<<n<<std::endl;}
    void f() && { std::cout<<"R-value and n = "<<n<<std::endl;}
};

int main(){
    C c(10);

    c.f();      // L-value and n = 10

    C(20).f(); // R-value and n = 10
}
