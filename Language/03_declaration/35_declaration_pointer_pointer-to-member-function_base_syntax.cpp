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
    void f(int n){ std::cout<<"n = "<<n<<std::endl; }
};

int main(){
    /*  Pointer to member function
        A pointer to non-static member function f which is a member of class C
        can be initialized with the expression &C::f exactly. Expression such
        as &(C::f) or &f inside C's member function do not form pointers to _
        member function.
        Such pointer may be used as the right-hand operand of the pointer-to-
        member access operators 'operator.*' and 'operator->*'. The resulting
        expression can be used only as the left-hand operand of a function-
        call operator
    */

    void (C::* pf)(int ) = &C::f;       // pointer to member f of class C
    C c;
    c.f(10);      // regular invoking
    (c.*pf)(10);  // special invoking for pointer to member

    // create pointer object
    C* pc = &c;

    pc->f(10);      // regular invoking
    (pc->*pf)(10);  // special invoking for pointer to member.
}












