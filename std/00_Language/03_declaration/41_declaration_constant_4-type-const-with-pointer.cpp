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
    /*  Constant
        If constant/volatile appears before * in the pointer declaration,
        it is part of decl-specifier-seq and applies to the pointer-to
        object. ( in fact const int* p means p is constant value )
        If constant/volatile appears after * in the pointer declaration,
        it is part of declarator and applies to the pointer that is being
        declared. ( in fact int* const p means, p pointer is constant not value of p )

        Syntax          meaning
        const T*        pointer to constant object ( object cannot change, but the pointer yes )
        T const*        pointer to constant object, ( same as above ), still const is before *

        T* const        constant pointer to object ( object can change, but pointer no )

        const T* const  constant pointer to constant object ( both of them are constant and not allow to change )

    */
    int n = 10;

    // const T*
    const int* i1;     // object is constant, but not pointer, It is better to assign
    int const* i2;     // same as above, object is constant, but not pointer. It is better to assign

    // error: because it has not been assigned before.
    // i1 = 3;

    // T* const
    int* const i3 = &n;

    // const T* const
    const int* const i4 = &n;
    // error: location is const ( read-only )
    // *i4 = 10;

}












