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
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    * final specifier               - explicit specifier
***************************************************************
    final specifier
    Specifies that a virtual function can not be overridden in a
    derived class or that class can not be inherited from
    with virtual function
    with pure-virtual function
    with class-key ( struct X final, class X final )
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>


/// final
// Final is an identifier with a special meaning when used in a member
// function declaration or class head. In other contexts it is not
// reserved and may be used to name object and function

struct B {
    virtual int f() final {}
    virtual int j(){}
    int s(){}
};
struct D final: B {     // struct B is final. So class can not be inherited from B
//    int f();            // error, in B::f() is final
    int j() final {}    // okay, and here is final
    int s(){}           // no related to B::s, it is a member of D::
};
//struct C: D {};         // error

int main(){

}







