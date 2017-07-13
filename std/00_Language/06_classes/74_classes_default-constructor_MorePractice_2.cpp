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
    A(int a=1, int b=2, int c=3){}  // it is a default constructor
    A(){}                           // it is a default constructor, too
                                    // here are correct, no error in compile-time
                                    // but it is ambiguous, when creating an object
};


int main(){
    A a;    // error: call of overloaded ‘A()’ is ambiguous
}



