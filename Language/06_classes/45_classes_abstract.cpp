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


/// abstract class

struct Base {
    virtual int g(){}
    virtual ~Base(){}
};
struct A : Base {
    // okay, declares three member function that two of them are pure, f() and g()
    virtual int f() = 0;
    virtual int g() override = 0;
    virtual int h();

    // okay, destructor can be pure
    ~A()=0;

    // wrong syntax, pure-specifier on a function definition is error
//    virtual int b() = 0 {}
    // or
//    virtual int c(){} = 0;
};

// Note:
// An abstract class is a class that either defines or inherits at least one
// function for which the final overrider is pure virtual.

int main() {
}






