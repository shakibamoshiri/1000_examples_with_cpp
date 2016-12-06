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
    * access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Access Specifier
    In a member specification of a class / struct or union, define
    the visibility of subsequence member.
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// access specifier, name lookup
// A name that is private accessing to unqualified name lookup
// may be accessing through qualified name lookup.
class A {};
class B: private A {};
class C: public B {

    // so here A in unaccessible since is private inside B

    A* p;   // error, unqualified name lookup find A as the private base of B
            // compiler says:
            // error: ‘class A A::A’ is inaccessible

    ::A* p2;    // okay, qualified name lookup finds the namesapce-level declaration
};

int main() {

}






