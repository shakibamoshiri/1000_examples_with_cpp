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
    - override specifier            - converting operator
    - final specifier               * explicit specifier
***************************************************************
    explicit specifier
    Specifies constructor and conversion operator (since c++11 )
    that do not allow implicit conversion or copy-initialization

    Syntax:
    explicit class-name (parameter)
    explicit operator type () since c++11
*/

#include <iostream>
#include <string>
#include <utility>
// #include <cstdlib>

/// Note
// A constructor with a single non-default parameter (until c++11)
// that is declared without function specifier explicit is called
// a converting constructor.
//
// Both constructor ( copy / move ) and user-defined conversion function
// may be function template: the meaning of 'explicit' does not change.

struct A {
    A (int){}       // converting constructor
    A (int, int){}  // converting constructor ( c++11)
    operator int() const {return 0;}    // also
};
struct B {
    explicit B(int){}   // copy initialization does not allow
    explicit B(int,int){}   // copy initialization does not allow
    explicit operator int()const{return 0;}   // copy initialization does not allow
};

int main(){
    A a1 = 1;       // okay copy-initialization selects A::A(int)
    A a2(2);        // okay direct-initialization selects A::A(int)
    A a3 {4,5};     // okay direct list-initialization selects A::A(int,int)
    A a4 = {4,5};     // okay copy list-initialization selects A::A(int,int)
    int i1 = a1;    // okay, copy-initialization selects A::operator int()
    int i2 = static_cast<int>(a2);  // okay, static_cast performs direct-initialization
    A a5  = (A)1;   // okay, explicit cast performs static_cast

//    B b1 = 1;       // error, copy-initialization does not consider B::B(int)
    B b2(2);        // okay, direct-initialization selects B::B(int)
    B b3 {4,5};     // okay, direct-list-initialization
//    B b4 = {4,5};   // error
//    int i3 = b1;    // error,
    int i4 = static_cast<int>(b2);  // okay static_cast preforms direct-initialization
    B b5 = (B)1;    // okay explicit cast performs static_cast
}
