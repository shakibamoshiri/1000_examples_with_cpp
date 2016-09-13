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

template<typename T> T f (T t) { return t;}

template<typename A, typename B>
void v (A a=0, B b=0){
    std::cout<<a<<' '<<b<<std::endl;
}

int main(){
    /*
        Pointer to template function.
    */
    std::cout<<f(1)<<std::endl;
    v<int,int>(1,2);

    int (*p)(int) = f;      // it means int f(int)
    char (*c)(char) = f;    // it means char f(char)

    void (*pv1)(int,int) = v;           // it means void v (int, int)
    void (*pv2)(const char*, float) = v;    // it means void v ( const char*, float);

    v("hello",3.14);
    (*pv2)("hello",3.14);       // same as above

    v<const char*,int>();       // Because of default parameter is possible.
}












