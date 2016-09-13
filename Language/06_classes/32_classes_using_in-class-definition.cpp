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

/// using, in a class definition
// Using-declaration introduces a member of a base class into the
// derived class definition, such as to expose ( to show sth that
// is usually hidden ) a protected member of base class as public
// member of derived class.
// Note: the derived class member hides  or overrides ( does not
// conflict with ) the member that is introduced form the base class.

struct B {
    virtual void f(int) { std::cout<<"virtual B::f\n";}
    void g(char)        { std::cout<<"B::g\n";}
    void h(int)         { std::cout<<"B::h\n";}
protected:
    int m;
    typedef int value_type;
};

struct D : B {
    using B::m; // here, D::m is public
    using B::value_type;    // here, D::value_type is public

    using B::f;
    void f(int) { std::cout<<"D::f\n";}     // D::f(int) overrides B::f(int)

    using B::g;
    void g(int) { std::cout<<"D::g\n";}     // both g(int) and g(char) are visible as member of D
    // override g(int)
    // but not override g(char)

    using B::h;
    void h(int) { std::cout<<"D::h\n";}
};

int main(){

    D d;
    B& br = d;

    //br.m;   // error, it is protected
    d.m;    // okay, it is a public in D class
    br.f(1);    // calls derived f()
    d.f(2);     // also calls derived f()
    d.g(3);     // calls derived g(in)
    d.g('c');   // derived has no g(char) override, so call base g(char)
    br.h(4);    // has a h() so calls base h()
    d.h(0);      // calls derived h();
}
