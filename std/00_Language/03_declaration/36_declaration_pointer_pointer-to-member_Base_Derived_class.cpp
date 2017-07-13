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

struct Base {
    void f(int n){ std::cout<<"n = "<<n<<std::endl; }
};
struct Derived : Base {};
int main(){
    /*  Pointer to member function
        Pointer to member function of a base class can be implicitly converted
        to pointer to the same member function of a derived class
    */
    Base b;
    b.f(10);        // common invoking

    Derived d;
    d.f(10);        // common invoking

    void (Base::* bf)(int) = &Base::f;     // assignment pointer-to-member function base class
    void (Derived::* df)(int) = bf;     // assignment pointer-to-member function derived class through base class

    std::cout<<(std::string(10,'_'))<<std::endl;

    (d.*bf)(10);        // invoking through derived class with pointer-to-member of base class
    (d.*df)(10);        // invoking through derived class with its pointer-to-member

}












