/*
Function:
    declaring function
    default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
    Declaring Function
**********************
    parameter list
syntax:
1   attribute ( optional ) dss declarator
2   attribute ( optional ) dss declarator = initializer
3   attribute ( optional ) dss abstract-declarator (optional)
4   attribute ( optional ) dss abstract-declarator (optional) = initializer
5   ...
6   void


*/

#include <iostream>
#include <string>
#include <array>

int main(){
    // if any of the function parameter uses a placeholder ( either auto or a constrained )
    // the function declaration is instead on abbreviated function template declaration
    void f(auto (auto::* )(auto));  // #1
    template<typename T, typename R, typename E> void f(T (R::*)(E));   // same as #1

    void g(const C1*, C2&); // #2 ( assuming C1 and C2 are concepts )
    template<C1 T, C2 R> void g(const T*, R&);  // same as #2

    // parameter named declared in function declaration are usually for only
    // self-documentation purposes. They are used ( but remain optional ) in
    // function definition.
    // because of these rudes, the following function declarations declares
    // exactly the same function
    int f(char s[3]);
    int f(char []);
    int f(char* s);
    int f(char* const);
    int f(char* volatile s);

    // the following declarations also declare exactly the same function
    int f(int());
    int f(int (*g)());

    // the comma before the ellipsis parameter that indicates variadic argument
    // is optional, even if followed the ellipsis that indicates a parameter pack
    // exception, so the following function template are exactly the same:
    template<typename ... Args> void f(Args..., ...);   // comma plus space
    template<typename ... Args> void f(Args... ...);    // only space
    template<typename ... Args> void f(Args......);     // nothing
}










