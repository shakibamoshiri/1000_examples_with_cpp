/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            * converting operator
    - final specifier               - explicit specifier
***************************************************************
    converting constructor
    A constructor that is not declared with the specifier 'explicit' and
    which has one non-default parameter ( until c++11 ) is called a
    converting constructor.
*/

#include <iostream>
#include <string>
#include <utility>
// #include <cstdlib>

/// explicit
// Unlike explicit constructor, which are only considered during "direct initialization"
// ( which includes 'explicit converting' such as static_case ), converting constructor
// are also considered during copy initialization, as part of use-defined conversion sequence.
/// note:
// non-explicit user-defined conversion function also specifies an implicit conversion

struct A {
    A(int) {}       // converting constructor
    A(int, int) {}  // converting constructor c++11
};
struct B {
    explicit B(int) {}          // only accepts direct-initialization
    explicit B(int ,int) {}     // only accepts direct-initialization
};


int main(){
    A a1 = 1;       // okay, copy-initialization selects A::A(int)
    A a2(2);        // okay, direct-initialization selects A::A(int)
    A a3 {3,4};     // okay, copy-list-initialization select A::A(int, int)
    A a4 = {5,6};   // okay, copy-list-initialization select A::A(int, int)
    A a5 = (A)1;    // okay, explicit cast performs static_cast, direct-


//    B b1 = 1;       // error, copy-initialization does not consider B:B(int)
    B b2(2);        // okay, direct-initialization selects B::B(int)
    B b3 {4,5};     // okay, direct-list-initialization selects B::B(int, int)
//    B b4 = {5,4};   // error, copy-list-initialization does not consider B:B(int, int )
    B b5 = (B)1;    // okay, explicit cost performs static_cast, direct-initialization
}
