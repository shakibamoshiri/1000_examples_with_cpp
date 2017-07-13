/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    * using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    using declaration
    Introduces a name that is defined elsewhere into the declarative region
    where this using-declaration appears.

    Syntax:
    using typename(optional) nested-name-specifier unqualified-id;

    Using-declaration can be used to introduce namespace mmeber into
    other namespce and block scopes, or to introduce base class
    members into derived class definition


*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// using, inheritance constructor

// I am not sure about this sample, although en.reference says it is correct
// but it has more that several error in compile-time


// If the constructor was inherited from multiple base class sub-object
// of type B, the program is ill-formed, similar to multiply-inherited
// non-static member function

struct A { A(int); };
struct B: A { using A::A; };
struct C1 : B { using B::B; };
struct C2 : B { using B::B; };

struct D1 : C1, C2 {
    using C1::C1;
//    using C2::C2;
};
//D1 d1(-1);      // ill-formed, constructor inherited from B base sub-object

struct V1 : virtual B { using B::B; };
struct V2 : virtual B { using B::B; };

struct D2 : V1, V2 {
    using V1::V1;
//    using V2::V2;
};
//D2 d2(-1);

struct L { L(int); };
struct I { I(int); };
struct U : I , L {
    using L::L;
    using I::I;
    U(int);     // okay, U::U(int) hides both I::I(int) and L::L(int)
};
U u(2);


int main(){
}
