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

struct Base {/* no field */ };
struct Derived : Base { int m;};

int main(){
    /*
        Conversion in the opposite direction, from a pointer to member
        of a derived class to a pointer to member of an unambiguous non
        -virtual base class, is allowed with static_cast and explicit cast,
        even if the base class does not have that member ( but the most
        derived class does, when the pointer is used for access )
    */

    int Derived::* derivedPointer = &Derived::m;

    int Base::* basePointer = static_cast<int Base::*>(derivedPointer); //or below:
    // int Base::* basePointer = (int Base::*)derivedPointer;

    Derived d;
    d.m = 3;
    std::cout<<d.*derivedPointer<<std::endl;    // okay

    Base b;
    std::cout<<b.*basePointer<<std::endl;       // okay, compiles, but undefined behavior

}












