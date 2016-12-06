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
#include <utility>
#include <exception>

/// virtual function

struct Base {
    virtual void f() { std::cout<<"Base::f()\n";};
};
struct Derived : Base {

    // using virtual keyword is optional, only definition the base function exactly, make it virtual
    // so void f() is a virtual function
    void f() { std::cout<<"Derived::f()\n";}
    // Also override keyword is optional
    // okay, void f() override {}
};

int main(){

    Base b;
    Derived d;

    // virtual function calls through reference
    Base& br = b;
    Base& dr = d;

    br.f();     // call Base
    dr.f();     // calls Derived

    // virtual function calls through pointer
    Base* bp = &b;
    Base* dp = &d;
    bp->f();    // calls Base
    dp->f();    // calls Derived

    // non-virtual function call
    br.Base::f();   // calls Base
    dr.Base::f();   // calls Base

    /*
            Base::f()
            Derived::f()
            Base::f()
            Derived::f()
            Base::f()
            Base::f()

            Process returned 0 (0x0)   execution time : 0.008 s
            Press ENTER to continue.
    */
}
