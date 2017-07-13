/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    * static specifier              - bit field
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
    static specifier
    Inside a class, declares members not bound to specific instances ( instance means: a particular example or case of something )

    syntax:
    static data member      : declares a static data member
    static function member  : declares a static function member

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// access
// to refer to a static member 'm' of classes T, two forms may be used:
// qualified name T::m
// or member access E.m
// or               E->m
// where E is an expression that equivalent to T or T* respectively.
// When in the same name class scope, the qualification is unnecessary:

struct X {
    static int n;       // declaration
    static void f();    // declaration
};

// some function returning X type
X somef (){
    return X();
}

void f(){
    X::f();     // X::f is a qualified name of static member function
    somef().f();    // g().f is a member access expression referring to a static member function
}

// definition X::n and X::f
int X::n = 7;
void X::f(){
    n = 1;
    // error: ‘this’ is unavailable for static member functions
    // this->n;
    // static member function has no this pointer
}



int main(){
    X x;
//    x.n;    // okay
    std::cout<<x.n<<std::endl;
    X* y = &x;
//    y->n;   // okay
    std::cout<<y->n<<std::endl;
}
