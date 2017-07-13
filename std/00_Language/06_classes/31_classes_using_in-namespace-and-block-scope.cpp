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

/// using, in namespace and block scope

using std::string;
using std::cout;

int main(){
    // no needs to use std::
    string str("using-declaration");

    // no needs to use std::
    // but with endl needs
    cout<<str<<std::endl;
}
