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

struct B1 { B1 (int, ... ){}};
struct B2 { B2 (double) {}  };

int get();  // froward declaration

struct D1 : B1 {
    using B1::B1;   // inherits B1 ( int, ... )
    int x;
    int y = get();
};

void test(){

    // Since B1 is inherited to D2 now D2 has a constructor like B1
    // B1 ( int, ... )
    // D1 ( int, ... ) <---- inherited constructor

    // it gives the error of no matching function
    // that I think parameter-packing does not inherit to derived class
    // since D1( 2 ), with one int is accept but with more than one, not accept
    // also if B1 would be B1 (int, int) then D1 accepts D1(2,3) , etc.

//    D1 d(2,3,4);    // okay, B1 is initialized by calling B1(2, 3, 4),
                    // then d.x is default-initialized (no initialization is preformed ),
                    // then d.y is initialized by calling get()
//    D1 e;           // error, D1 has no default constructor
};

struct D2 : B2 {
    using B2::B2;   // inherits B2 ( double )

    B1 b;           // it must be constructs, but since B1 has no default constructor, so object of
                    // D2 can not constructor, so we need remove 'B1 d' or default constructor inside B1
};
//D2 d(1.2);          // error, B1 has not default constructor

struct W { W(int); };
struct X : virtual W {
    using W::W;     // inherits W(int)
    X()=delete;
};
struct Y : X {
    using X::X;
};
struct Z : Y, virtual W {
    using Y::Y;
};
Z z(0);     // complier gives error, use of deleted function Z::Z(int)
            // but in en.reference.com c++ has said: OK: initialization of Y does not
            // invoke default constructor of X
            // but here, invokes!





int main(){


}
