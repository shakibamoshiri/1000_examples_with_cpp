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
    - virtual function specifier    - copy constructor
    * abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Abstract Class ( almost opposite: Concrete class)
    Defines an abstract type which can not be instantiated, but can be used as a base class

    pure-virtual function is a virtual-function that = to 0
    declaration virtual-function (optional) = 0;

    Note: pure-specifier ( 0 ) can not appear in a member definition
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// abstract class, virtual call
// Making a virtual call to a pure virtual function from a constructor
// or a destructor of the abstract class is undefined-behavior
// regardless of whether it has a definition or not.

struct A {
    virtual void f() = 0;   // pure-virtual
    virtual void g() {}     // non-pure virtual
    ~A(){
        g();        // okay, calls A::g()
       // f();        // undefined-behavior
        A::f();     // okay, non-virtual call
    }
};
// definition of the pure virtual function
void A::f(){ std::cout<<"A::f()"<<std::endl;}

struct C : A {
    void f() override {
        std::cout<<"C::f"<<std::endl;
        A::f();     // okay, call pure virtual function
    }
    void g() override {
        std::cout<<"C::g"<<std::endl;
    }
    ~C(){
     //  g();        // okay, calls C::g()
       // f();        // okay, calls C::f()
        // no need to use A::f
    }
};


int main() {
    C c;
    c.g(); // first call C::g, then call destructor ~A
}






