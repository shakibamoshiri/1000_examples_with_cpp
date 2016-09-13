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
        Pointer may appear as operands to the built-in indirection operator
        ( unary operator* ) , which returns the l-value expression identifying
        the pointed-to object.
    */
    int n =2 ;
    int* pn = &n;       // pointer to int
    int& rn = *pn;      // reference is bound to the l-value expression that identifies n
    rn = 22;             // stores the int 22 in n
    std::cout<<n<<std::endl;

    /*
        Because of the array-to-pointer implicit conversion, pointer to the first
        element of an array can be initialized with an expression of array type.
    */
    int arr[2];
    int* p1 = arr;      // pointer to the first element arr[0] (an int) of the array arr

    int i3[6][3][8];

    // error
    // int* p2 = i3;

    // okay
    int (*p2)[3][8] = i3;   // pointer to the first element i3[0] of the array i3
                            // which is an array of 3 arrays of 8 ints.


    /*
        Because of the derived-to-base implicit conversion for pointers,
        pointer to a base class can be initialized with the address of a
        derived class.
    */

    struct Base {};
    struct Derived : Base {};

    Derived d;
    Base* b = &d;

    // If derived is polymorphic such pointer may be used to make virtual function call.
}












