/*
Classes
    - class declaration
    - union declaration
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
    * override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    override specifier
    Specifies that  a virtual function overrides another virtual function
    with virtual function
    with pure-virtual function
    In both cases, final override, or, override final is possible
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>


/// override
struct B {
    void f (){}     // non-virtual function
    virtual void j (){}
    virtual void s() = 0;
};
struct D : B {
    void f(){}              // no related to struct B::f, it is a member of D::f
                            // using 'override' for this function is wrong
    void j() override {}    // overrides B::j for D
    void s() override = 0;  // overrides pure-virtual
};

int main(){

}







