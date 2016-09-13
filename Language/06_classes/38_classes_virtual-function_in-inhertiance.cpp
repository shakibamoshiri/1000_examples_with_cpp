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
#include <utility>
#include <exception>

/// virtual function
// For every virtual function, there is the final overrider, which is executed
// when a virtual function call is made. A virtual member function 'vf' of class
// 'Base' is the final overrider unless the derived class declared or inherits
// ( through multiple inheritance ) another function that overrides 'vf'.

struct A { virtual void f(){}; };       // A::f is virtual
struct B : A { void f(){}; };           // B::f overrides A::f in B

struct C : virtual B {
    void f(){                            // C::f overrides A::f in C
        std::cout<<"C::f and final of A::f\n";
    }
};

struct D : virtual B {};                // D does not introduces an override of A::f, so B::f is final in D
struct E : C, D {
    using A::f;                         // not a function declaration, just makes A::f visible to lookup
};


int main(){
    E e;
    e.f();      // D has no f to call, so this f belongs to C
                // C::f and final of A::f
    e.E::f();   // non-virtual-call calls A::f, which is visible is E
                // that was visible by using A::f

}
