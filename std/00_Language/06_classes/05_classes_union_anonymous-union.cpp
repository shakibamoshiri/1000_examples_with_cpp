/*
Classes
    - class declaration
    * union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
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
    union declaration
    A union is a special class type that can hold only one of its
    non-static data member at a time. The class specifier for a union
    declaration is similar to class or struct declaration
    union attribute class-head-name { member-specification};
    The union is only as big as necessary to hold it largest data member.
    The other data member are allocated in the same bytes as part of largest
    member.


*/

#include <iostream>
#include <string>
#include <vector>

/// Anonymous unions
// An unnamed union definition that does not define any object
// , pointer or reference is an anonymous union definition
// syntax: union { member-specification };

int main(){
    union { int a; const char* p;};
    a = 1;
    p = "this is an anonymous union";
    std::cout<<a<<' '<<p;
}
