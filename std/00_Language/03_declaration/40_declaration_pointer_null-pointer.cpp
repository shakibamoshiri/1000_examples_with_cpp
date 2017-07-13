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

int main(){
    /*
        Pointer of every type have a special value known as null pointer
        value of that type. A pointer that whose value is null does not
        point to an object or a function.
        To initialize a pointer to null or to assign the null value to an
        existing pointer, the null pointer literal nullptr, the null pointer
        constant NULL, or the implicit conversion from the integer value 0
        may be used.
    */

    int* n  = 0;        // okay
    int* n1 = NULL;     // okay
    int* n2 = nullptr;  // okay
}












