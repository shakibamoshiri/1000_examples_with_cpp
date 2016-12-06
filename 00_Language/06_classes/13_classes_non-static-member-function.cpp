/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    * non-static member function
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
    non-static member function
    A non static member function is a function that is declared in member
    specification of a class without a 'static' or 'friend' specifier

*/

#include <iostream>
#include <string>
#include <vector>

/// non-static member function
class S {
    int mf1();      // non-static member function declaration
    void mf2() volatile;    // non-static member function cv-qualified
    void mf3() &&;          // non-static member function reference qualified
    int mf4() const {
        return data;
    }                       // can be defined in-line
    virtual void mf5() final;   // can be virtual, can be final, or override
    S() : data(12){}        // constructor are member functions too.
    int data;
};
int S::mf1() {return 4;};   // if not definition in-line, it has to be defined at namespace
/*
A non-static member function of class X may be called:
    - for an object of type X using the class member access operator. ( a.b )
    - for an object of a class derived form X.
    - directly form within the body of a member function of X.
    - directly form within the body of a member function of a class derived form X.
    */
struct A {
    int n;
    void f();
};
void A::f(){
    n = 1;  // transformed to (*this).n;
    // okay
    // (*this).n;
    // (*this).f();
    // this->n;
    // this->f();
}

A a1, a2; // a1 no value and a2 no value
a1.f();     // now n = 1 ( changes the 'n' of a1 and no 'n' of a2

struct B {
    static int n;
    void f();
};
void B::f(){
    n = 1;
};
B b1, b2;
b1.f();     // now B::n equals to 1
            // it means 'n' for b1 and b2 are 1

int main(){
}
