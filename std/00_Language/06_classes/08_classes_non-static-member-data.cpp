/*
Classes
    - class declaration
    - union declaration
    * non-static member data
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
    non-static member data

*/

#include <iostream>
#include <string>
#include <vector>

/// non-static member data
//  Non-static data members are the variables that are declared in a member specification or a class
class S {
    int d1;             // non-static data member
    int a[10]={1,2};    // non-static data member with initializer (c++11)
    static const int d2=2;  // static data member with initializer
    virtual void f1(int)=0; // pure virtual member function
    std::string d3,*d4, f2(int);    // two data members and a member function
    enum {NORTH, SOUTH, EAST, WEST};
    struct nestedS {
        std::string s;
    }d5, *d6;
    typedef nestedS value_type, *pointer_type;
};

/*
    Any simple declaration are allowed, except:
    - extern and register storage class specifiers are not allowed.
    - thread_local storage class specifier is not allowed ( but it is allowed for static data members)
    - incomplete type are not allowed: in particular, a class C can not have a non-static data member
      of type C, although it can have a non-static data member of ty pe C& ( reference to C) or C*
      ( pointer to C)
    - a non-static data member can not have the same name as the name of the class if at least one user-
      declared constructor is present.
    * in addition, bit field declaration are allowed.

*/

int main(){
}
