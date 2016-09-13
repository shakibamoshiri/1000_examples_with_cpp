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

struct B1 {
    B1(int);
};
struct D1 : B1 {
    using B1::B1;
    // the set of inheritance constructors is:
    // B1 ( const B1& )     copy constructor
    // B1 ( B1&& )          move constructor
    // B1 ( int )           user-defined constructor

    // D1 has the following constructor:
    // D1 ()                default constructor
    // D1 ( const D1& )     copy-con
    // D1 ( D1&& )          move-con
    // D1 ( int )           inherited, form base class B1
};

struct B2 {
    B2 (int=22, int=32);
};
struct D2 : B2 {
    using B2::B2;

    // the set of inheritance constructor is:
    // B2 ( const B2& )     copy-constructor
    // B2 ( B2&& )          move-con
    // B2 ( int=22, int=32)
    // B2 ( int=22 )
    // B2 ()

    // D2 has the following constructors:
    // D2 ()
    // D2 ( cosnt D2& )     copy-con
    // D2 ( D2&& )          move-con
    // D2 ( int, int )      inherited
    // D2 ( int )           inherited
};
// The inherited constructors are equivalent to user-defined constructor with
// an empty body and with a member initializer list consisting of a single nested
// specifier, which forwards all of its argument to the base class constructor.

int main(){


}
