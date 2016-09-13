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

struct Base {int m;};
struct Derived : Base { /* int m; */ };

int main(){
    /*
        Pointer to member of a base class can be implicitly converted to pointer
        to the same member of a derived class
    */
    int Base::* basePointer = &Base::m;             // base has field m
    int Derived::* derivedPointer = basePointer;    // and also derived has field m through base

    Derived d;
    d.m = 1;

    std::cout<<d.*basePointer<<' '<<d.*derivedPointer<<' '<<d.m<<std::endl;




}












