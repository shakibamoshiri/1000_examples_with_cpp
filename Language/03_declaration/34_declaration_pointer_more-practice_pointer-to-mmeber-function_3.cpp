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
    A one = {10,&A::m,&A::f};

    std::cout<<one.m<<' '<<one.*(one.p)<<std::endl;         // output 10 10
    std::cout<<one.f()<<' '<<(one.*one.pf)()<<std::endl;    // output 10 10

    A* two = {&one};        // pointer object
                            // takes address of one ( regular object )

    // points to field and points to function
    std::cout<<two->m<<' '<<two->f()<<std::endl;                    // output 10 10

    // points to pointer-to-member-field and points to pointer-to-member-function.
    std::cout<<two->*(two->p)<<' '<<(two->*two->pf)()<<std::endl;   // output 10 10
}












