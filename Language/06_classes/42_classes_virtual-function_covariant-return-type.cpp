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

// ( covariant means: showing a tendency to change with another variable )
/// covariant return types
// If the function Derived::f overrides a function Base::f, their return types
// must either be the same or be 'covariant'. Two types are covariant, if they
// satisfy all of the following requirements:
/*
    -   both types are pointers or references (lvalue or rvalue) to
        classes. Multi-level pointers or references are not allowed.

    -   the referenced/pointed-to class in the return type of Base::f()
        must be a unambiguous and accessible direct or indirect base class
        of the referenced/pointed-to class of the return type of Derived::f().

    -   the return type of Derived::f() must be equally or less cv-qualified
        than the return type of Base::f().
*/

class B {};

struct Base {
    virtual void vf1(){};
    virtual void vf2(){};
    virtual void vf3(){};

    virtual B*   vf4(){};
    virtual B*   vf5(){};
};

class D : private B {
    friend struct Derived;  // in Derived B is an associable base of D
};

class A;        // forward declaration

struct Derived : public Base {
    void vf1(){};       // virtual overrides Base::vf1()
    void vf2(int){};    // non-virtual, override but not active, and hides Base::vf2()
//    char vf3();         // error, override Base::vf3, but has different and non-covariant return type
    D*   vf4(){};         // overrides B* B::vf4() and has covariant return type
//    A*   vf5();         // error, A is incomplete type
};

int main() {
    Derived d;
    Base& br = d;
    Derived& dr = d;

    br.vf1();   // calls Derived::vf1()
    br.vf2();   // calls Base::vf2(), because Derived has not void vf2() and has void vf2(int)
//    dr.vf2();   // error, no match function and need one int at least
    dr.vf2(-1); // okay , calls Derived::vf2(int);

    B* p = br.vf4();    // calls Derived::vf4() and convert the result to B*
//    D* q = br.vf4();    // calls Derived::vf4() and does not convert the result to B* ( invalid conversion )
}






