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

struct C {
    int m;
    int f(){}
};

int main(){
    /*
        A pointer to non-static data member 'm' which is member of class C can
        be initialized with the expression &C::m exactly. Expression such:
        &(C::m) or &m inside C's member function do not form pointer to member.
    */
    int C::* p = &C::m;             // pointer to member m of class C
    C c = {5};
    std::cout<<c.m<<std::endl;      // member of object
    std::cout<<c.*p<<std::endl;     // pointer-member of object

    C* pc = &c;
    std::cout<<pc->m<<std::endl;    // member of pointer-object
    std::cout<<pc->f()<<std::endl;      // function-member of pointer-object


    int (C::* pf)() = &C::f;            // pointer-member-function

    std::cout<<c.f()<<std::endl;        // member-function of object
    std::cout<<(c.*pf)()<<std::endl;    // pointer-member-function of object

    std::cout<<(pc->*pf)()<<std::endl;  // pointer-member-function of pointer-object




}












