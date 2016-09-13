/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    * derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    derived classes
    Any type class may be declared as derived form one or or more
    base classes which, in turn, may be derived from their own base
    classes, formating an inheritance hierarchy.

    Syntax:
    attribute (optional) : access-specifier(optional) virtual-specifier(optional) class-or-decltype

    Note:
    If access-specifier is omitted ( leave out ), it defaults to 'public' for classes
    declared with class-key 'struct' and to 'private' for classes declared class-key 'class'

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// derived classes
struct Base {
    int a, b, c;
};

// every object of type derived includes Base as a sub-object
struct Derived : Base {
    int d;
    // also int a, b, c;
};

// every object of type Derived2 includes Derived and Base as sup-objects
struct Derived2 : Derived {
    int e;
    // also int a, b, c;
    // and  int d
};





int main(){

}
