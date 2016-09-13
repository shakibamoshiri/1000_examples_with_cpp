/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             * destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    destructor
    A destructor is a special member-function that is called when the
    lifetime of an object ends. The purpose of the destructor is to
    free the resources that the object may have acquired its lifetime.

    syntax:
    ~ class-name();
    virtual ~ class-name();
    ~ class-name() = default;
    ~ class-name() = delete;

*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

/// Explanation
// The destructor is called whenever an object's lifetime ends, which includes:
//  - program termination, for object with static storage duration
//  - thread exit, for objects with thread-local storage duration
//  - end of scope, for objects with automatic storage duration and for temporaries
//    whose life was extended by binding ot a reference
//  - delete expression, for object with dynamic storage duration
//  - end of the full expression, for nameless temporaries
//  - stack unwinding, for objects with automatic storage duration when an exception
//    escapes their block, uncaught.

/// Implicitly-declared destructor
// If no user-defined destructor is provided for a class type ( struct,class or union )
// the complier will always declare a destructor as an: "inline public".

/// virtual destructor
// Deleting an object through pointer to base undefined-behavior unless the
// destructor in the base class is virtual.
class Base {
    public:
    virtual ~Base(){}
};
class Derived: public Base {
    public:
    virtual ~Derived(){}
};

int main(){
    Base* bp = new Derived;
    delete bp;
}



