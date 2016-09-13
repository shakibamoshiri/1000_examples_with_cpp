/**
/// Namespaces
///
///
Syntax:

1   namespace ns_name { declaration }
2   inline namespace ns_name { declaration }
3   namespace { declaration }
4   ns_name::name
5   using namespace ns_name;
6   using ns_name::name;
7   namespace name = qualified-namespace;
8   namespace ns_name::name. since c++ 17

If a function was introduced by a using-declaration, declaring a function
with the same name and parameter list is ill-formed ( unless the declaration
is for the same function ). If a function template was introduced by a using-
declaration, declaring a function template with the same name, parameter type
list, return type,and template parameter list is ill-formed Two using-declaration
can introduce functions with the same name and parameter list, but if a call to
that function is attempted, the program is ill-formed.

**/
#include <iostream>
/// user defined
//#include "temp.h"

namespace B {
    void f(int);
    void f(double);
}
void B::f(int){}
void B::f(double){}

namespace C {
    void f(int);
    void f(double);
    void f(char);
}
void C::f(int){}
void C::f(double){}
void C::f(char){}

void h() {
    using B::f;     // introduces B:: f(int), f(double)
    using C::f;     // introduces C:: f(int), f(double), f(char)
    f('f');         // call C::f(char)

//    f(1);           // error: which one ? B::f(int) or C::f(int). Ambiguous
//    void f(int);    // error: f overloading conflicts with B::f(int) and C::f(int)
}
int main(){

}













