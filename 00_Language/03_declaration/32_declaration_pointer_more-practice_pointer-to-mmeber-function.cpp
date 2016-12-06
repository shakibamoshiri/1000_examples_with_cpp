/**
/// Pointer Declaration
///
///
Declares a variable of a pointer or pointer-to-member type

Syntax:

A pointer declaration is any simple declaration whose declarator has the form:

* attribute ( optional ) const/volatile ( optional ) declarator
nested-name-specifier * attribute ( optional ) const/volatile ( optional ) declarator
1   Pointer Declarator: The declaration s* d; declares d as a pointer to the type
    determined by decl-specifier-seq s;
2   Pointer to Member Declarator: The declaration s c::* d; declares d as a pointer
    to member of c of type determined by decl-specifier-seq s.

**/
#include <iostream>
#include <string>
struct A {
    int m;
    int f() { return m;}

    int  A::* p;
    int (A::* pf)();

};
int main(){
    A a;
    a.m = 10;
    a.p = &A::m;
    a.pf = &A::f;

    std::cout<<a.m<<' '<<a.*(a.p)<<std::endl;           // output: 10 10
    std::cout<<a.f()<<' '<<(a.*(a.pf))()<<std::endl;    // output: 10 10

    // create a pointer-to-member-field
    int A::* A::* pp = &A::p;

    // create a pointer-to-member-function
    int (A::* A::* ppf)() = &A::pf;

    std::cout<<a.*(a.*pp)<<' '<<(a.*(a.*ppf))()<<std::endl;     // output: 10 10
}












