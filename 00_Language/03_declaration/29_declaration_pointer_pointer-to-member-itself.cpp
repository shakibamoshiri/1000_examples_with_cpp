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
    int A::* const p;
};
int main(){
    /*
        The pointer-to type of a pointer-to-member may be a pointer-to-member
        itself: pointer to members can be multilevel, and can be cv-qualified
        differently at every level. Mixed multi-level combinations of pointer
        and pointer-to-member are also allowed.
    */
    // non-const pointer to member which is a const pinter to non-const member
    int A::* const A::* p1 = &A::p;

    const A a = {1, &A::m};
    std::cout<<a.*(a.*p1)<<std::endl;

    // regular non-const pointer to a cosnt pointer-to-member
    int A::* const* p2 = &a.p;
    std::cout<<a.**p2<<std::endl;
}












