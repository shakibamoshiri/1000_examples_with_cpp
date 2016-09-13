/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  * constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    constructor and member initializer lists
    Constructor is a special non-static member-function of a class
    that is used to initialize objects of its class type.

    The only specifiers allowed in the declaration-specifier-sequence
    of a constructor  are 'friend', 'inline', 'explicit', and 'constexpr'.
    In particular, no return type is allowed, and no cv-qualified are
    allowed either.

    The body of a function definition of any constructor, before the opening
    brace of the compound statement( means {} ) may include the 'member initializer list',
    whose syntax is the color character (:,) and following by comma-separated list of
    or more member-initializers, echo of which has the following syntax:
    class-or-identifier (expression list)
    class-or-identifier brace-init-list     c++11
    parameter-pack list ...                 c++11

*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

/// initialization order
/// irrelevant: important to or connected with a situation
// The order of member initializers in the list is irrelevant: the actual order is as following:
// first:   for the most-derived class ...
// second   direct base class are initialized
// third    non-static data member are initialized
// finally  the body of the constructor are executed

struct Base {
    int n;
    Base(int t): n(t) {}
}
class C {
    unsigned char x;
    unsigned char y;
    C(int x):
        Base(123),  // initializes base class
        x(x),       // x member is initializes with x parameter
        y(0)        // y member initializes to 0
    {}              // empty compound statement

     C (double d):
         y(a+1),
         x(y)       // x will be initialized before y, its value here is indeterminate( determinate: fix and defined, in...: that cannot be identified easily or exactly )
    {}

    C() try:        //function try block begins before the function body, which include initializer list
        Base(555),
        x(0),
        y(0)
        {
            // ...
        }
        catch(...){
            // exception occurred on initialization
        }





int main(){
}



