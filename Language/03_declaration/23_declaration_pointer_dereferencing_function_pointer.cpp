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

int d(){}

int main(){

    // Dereferencing a function pointer yields the l-value identifying the pointer to function.
    int d();
    int (*p1)() = d;        // pointer p is pointing to d.
    int (&r1)() = *p1;      // the l-value that identifies d is bound to a reference.
    r1();                   // function d invoked through l-value reference.
    (*p1)();                // function d invoked through the function l-value.
    p1();                   // function d invoked directly through the pointer.
}












