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
    // const pointer to non-const member;
    const int A::* p;
};
int main(){
    const int A::* A::* pp = &A::p;
    int A::* pm = &A::m;

    A a;
    a.m = 10;
    a.p = pm; // it means a.p = &A::m
    std::cout<<a.m<<' '<<a.*(a.p)<<std::endl;

    std::cout<<a.*pm<<' '<<a.*(a.*pp)<<std::endl;
    // a.*(a.*pp) means pointer to member that itself is a pointer to member.
    // it become: pointer to member a.*
    // pp: pointer to member to pointer to member.
    // first a.* means inside main function
    // and a.*(a.*pp) means 'a' points to ( 'a' points to )
}












