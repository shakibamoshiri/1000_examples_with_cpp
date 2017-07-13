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

/// Example
struct A {
    int i;
    A(int i): i(i){}
    ~A(){
        std::cout<<"~A"<<i<<std::endl;
    }
};

int main(){
    A a1(1);
    A* p;
    {
        // nested scope
        A a2(2);
        p = new A(3);
    }   // a2 out of scope
    delete p;   // calls the destructor of a3

    /// ordering in release
    // first    a2
    // second   a3
    // third    a1
}



