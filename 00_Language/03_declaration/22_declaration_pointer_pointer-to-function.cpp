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
void f(int t){
    std::cout<<t<<std::endl;
}
int fi(int t){
    return t;
}
int main(){
    /*
        Pointer to Function.
        A pointer to function can be initialized with an address of a non-member
        function or a static member function. Because of the function-to-pointer
        implicit conversion, the address-of operator is optional
    */
    void (*p1)(int) = &f;   // okay
    void (*p2)(int) = f;    // okay, same as &f

    /*
        Unlike function or reference to function, pointers to functions are
        objects and thus be stored in array, copies, assigned, etc.

        A pointer to function can be used as the left-hand of the function
        call operator, this invokes the pointer-to-function.
    */
    int (*p3)(int) = fi;
    int x = p3(10);
    std::cout<<x<<std::endl;

}












