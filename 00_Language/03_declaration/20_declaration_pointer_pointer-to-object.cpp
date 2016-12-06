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
        Pointer to object:
        A pointer to object can be initialized with the return value of the
        address of operator applied to any expression of object type, including
        another pointer type.
    */
    int n = 20;                 // regular object
    int* pn = &n;               // pointer to int
    int* const* ppn = &pn;      // non-const pointer to const pointer to non-const int (n)

    int** const ppn2 = &pn;      // it is like above ( ppn )
                                 // int** const and int* const* had the same meaning.
                                 // also int* const and int const* had the same meaning.

    std::cout<<"n       : "<<n<<std::endl;
    std::cout<<"*pn     : "<<*pn<<std::endl;
    std::cout<<"**ppn   : "<<**ppn<<std::endl;
    std::cout<<"**ppn2  : "<<**ppn2<<std::endl;

}












