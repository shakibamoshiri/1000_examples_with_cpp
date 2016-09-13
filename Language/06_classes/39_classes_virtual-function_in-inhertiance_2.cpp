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
    * virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    virtual function specifier
    Specific that a non-static member function is virtual and supports dynamic binding
*/

#include <iostream>
#include <string>
#include <cstdlib>
/// virtual function, in inheritance
// If a function has more than one final override, the program is ill-formed:


struct A {
    virtual void f(){puts("A::f\n");}
};
struct VB1 : virtual A {
    void f(){ puts("VB1::f\n");}
};
struct VB2 : virtual A {
    void f() {puts("VB2::f\n");}
};
/// error: no unique final overrider for ‘virtual void A::f()’ in ‘Two_final’
// struct Two_final : VB1, VB2 {};
struct Fix_two_final : VB1, VB2 {
    void f() { puts("fix_two_final::f\n");}
};

struct VB1_2 : virtual A {};    // okay, VB1_2 is final of A::f
struct C : VB1_2, VB1 {};       // okay, has no two final override
                                // in C, the final overrider of A::f is VB1
int main(){
    VB2 vb2;
    vb2.f();    // VB2::f
}
