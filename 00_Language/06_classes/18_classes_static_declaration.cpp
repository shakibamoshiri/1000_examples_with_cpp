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

/// explanation
// static member of a class are not associated with the object of the class.
// They are independent object with static storage duration or regular function
// defined in namespace scope, only once in the program.

class E { static int n;};   // need to use static in declaration
int E::n = 1;               // does not need to use static again.

/// incomplete type
// the declaration inside a class body is not complete
struct Foo;
struct S {
    static int a[]; // declaration, incomplete type
    static Foo f;   // declaration, incomplete type
    static S s;     // declaration, incomplete type
};
int S::a[10];       // definition, complete type
struct Foo {};      // okay
Foo S::f;           // definition, complete type
S S::s;             // definition, complete type





int main(){
}
