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
#include <vector>
#include <algorithm>
#include <functional>

int main(){
    /*  Pointer to void
        Pointer to object of any type can be implicitly converted to pointer
        to void ( optionally cv-qualified ). The reverse conversion, which
        requires static_cast or explicit cast, yields the optional pointer value
    */
    int n =1 ;
    int* p1 = &n;
    void* pv = p1;
    int* p2 = (int*) pv;
    int* p3 = static_cast<int*>(pv);
    std::cout<<*p2<<' '<<*p3<<std::endl;    // output 1 1

    /*
        If the original pointer is pointing to a base class sub-object within an
        object of some polymorphic type, dynamic_cast may be used to obtain a
        void* that is pointing at the complete object of the most derived type.

        Pointers to void are used to pass objects of unknown type, which is common
        in C interface: std::malloc return void*, std::qsort expects a user-defined
        callback that accepts two const void* argument. pthread_create expects a
        user-provided callback that accepts and return void*. In all cases, it is the
        caller's responsibility to cast the pointer to the correct type before using.
        caller, here means someone who writes program ( programmer )
    */

}












