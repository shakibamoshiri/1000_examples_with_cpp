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
// A function with the same name but different parameter list does not
// override the base function of the same name, but hides it:
// when unqualified-name-lookup examines the scope of the derived class
// the lookup finds the declaration and does not examines the base class.

struct A {
    virtual void f(){
        std::cout<<"A::f"<<std::endl;
    }
};
struct B : A {
    void f(int=0){                      // B::f overrides, then hides A::f because of the same name
        std::cout<<"B::f"<<std::endl;   // but  does not work as dynamic binding
                                        // but still can be inherited
    }                                   // void f(int) inactive void f() of A
};
struct C : B {
    void f(){                           // Although A::f hides inside B but still can be inherited here
        std::cout<<"C::f"<<std::endl;
    }
};

int main() {
    B b;
    C c;
    A* base_pointer = &b;
    base_pointer->f();  // error, it must call B::f, but call A::f

    base_pointer = &c;
    base_pointer->f();  // okay , calls C::f

}






