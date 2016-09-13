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
    int A::* p;
};
int main(){
    int A::* A::* pp = &A::p;
    int A::* pm = &A::m;
    A a;
    a.m = 10;       // looks like m = 10
    a.p = &A::m;    // looks like A::* p = &A::m
                    // so we can use a.m
                    // and use a.*(a.m) that point to the &A::m
                    // because of before m gets 10 so (a.p) is 10 now
    std::cout<<a.m<<' '<<a.*(a.p)<<std::endl; // output 10 10
}












