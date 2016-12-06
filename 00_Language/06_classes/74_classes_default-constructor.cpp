/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  - constructor
    - derived class                 * default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Default constructor
    A default constructor is a constructor which can be called with no
    argument. Either defined with an empty parameter list, or with default
    argument provided for every parameter. A type with a public default
    constructor is DefaultConstructible

    Syntax:
    class-name();
    class-name::class-name();
    class-name() = delete;
    class-name() = default;
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

struct A {
    int x;
    A(int x=1):
        x(x) {} // user-default constructor
};
struct B: A {
    // B::B is implicitly-defined, calls A::A()
};
struct C {
    A ojb;  // C::C() is implicitly-defined, class A::A()
};
struct D: A {
    D(int y):
        A(y) {} // D::D() is not declared because another constructor is exists
};
struct E: A {
    E(int y):
        A(y) {}
    E() = default;  // explicitly defaulted, calls A::A()
};
struct F {
    int& r;
    const int c;
    // F::F() is implicitly defined as deleted. (why???)
};

int main(){
    A a;
    B b;
    C c;
//    D d;    // error: no matching function for call to ‘D::D()’
    E e;
//    F f;    // error: use of deleted function ‘F::F()’
}



