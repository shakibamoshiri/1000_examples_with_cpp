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
    * access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Access Specifier
    In a member specification of a class / struct or union, define
    the visibility of subsequence member.
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// access specifier, private member class

struct B {
    virtual void f() {  // f is a public member
        std::cout<<"B::f()"<<std::endl;
    }
};
class D : public B {
private:
    void f() override { // f is a private override member
        std::cout<<"D::f()"<<std::endl;
    }
};

class C :  B {
private:
    void f() override { // f is a private override member
        std::cout<<"C::f()"<<std::endl;
    }
};



int main() {
    B b;
    b.f();  // okay call, B::f()

    D d;
    // error, f in D is a private member so we can call that
    // d.f();

    // so since it is a virtual function inside B and also inside D
    // it is okay to call D::f through virtual-table of Base class
    B* pb = &d;
    pb->f();    // okay call D::f

    // NOTE: if instead of class D : public B {}
    // we write class D : B {}, without using 'public'
    // access we can not call D::f

    C c;
    // compile error
    // error: ‘B’ is an inaccessible base of ‘C’
    // pb = &c;
}






