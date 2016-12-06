/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    * virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    virtual function specifier
    Specific that a non-static member function is virtual and supports dynamic binding
*/

#include <iostream>
#include <string>
#include <cstdlib>

/// virtual function, in inheritance

// Note 1: override keyword with non-match parameter list is ill-formed
struct B {
    virtual void f(int){}
};
struct D : B {
    void f(int) override {}     // okay
//    void f(char) override {}    // ill-formed
//    void f(float) override {}   // ill-formed
//    void f(long) override {}    // ill-formed
};

// Note 2: overrode a function that already has 'final' key is ill-formed
struct BB {
    virtual void f() const final {}
};
struct DD : BB {
//    void f() override const {}
};

// Note 3: Non-member function and static member function can not be virtual
// so compiler says:
// error: member ‘f’ cannot be declared both virtual and static
struct C {
//    virtual static int f(){}
};

// Note 4: virtual function can not have any associated constraints.
struct E {
//    virtual void f() requires true; // error, constrained virtual function
};

int main() {

}






