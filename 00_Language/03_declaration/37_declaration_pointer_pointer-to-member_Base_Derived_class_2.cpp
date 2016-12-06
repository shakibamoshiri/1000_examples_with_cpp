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

struct Base {};
struct Derived : Base {
    void f(int& n){
        n *= n;
        std::cout<<"n = "<<n<<std::endl;
        }
};
int main(){
    /*  Pointer to member function
        Conversion in the opposite direction, form a pointer to member function
        of a derived class to pointer to member function of an unambiguous non-
        virtual base class, is allowed with static_cast and explicit cast, even
        if the base class does not have that member function ( but the most-derived
        class does, with the pointer is used for access )
    */

    // base class has no member function, but derived class has one.
    Derived d;
    // Base* pb = &d;
    // error
    // pb->f();

    void (Derived::* dp)(int&) = &Derived::f;
    void (Base::* bp)(int&) = static_cast<void (Base::*)(int&)>(dp);
    // or with explicit conversion
    // void (Base::* db3)(int) = (void (Base::*)(int)) dp;

    int n = 10;
    (d.*dp)(n);

    n = 10;
    Base b;
    (b.*bp)(n);
}












