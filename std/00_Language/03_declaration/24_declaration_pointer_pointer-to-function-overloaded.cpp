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

template<typename T>
T f (T t) { return t;}
double f (double d) { return d;}

int main(){
    /*
        A pointer to function may be initialized from an overload set which
        may include functions, function template specializations, and function
        template, if only one overload matches the type of the pointer ( see
        address of on overloaded function for more detail. )
    */
    int (*p)(int) = f;          // instantiates and selects f<int>;
    double (*d)(double) = f;    // f(double)

    std::cout<<p(1)<<std::endl;
    std::cout<<d(2.2)<<std::endl;

    // so this is possible, too
    char (*ch)(char) = f;
    std::cout<<ch('c')<<std::endl;
}












