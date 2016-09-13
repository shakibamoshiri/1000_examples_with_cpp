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

Using-declaration cannot name template-id, namespce, or a scoped enumerator.
Each using-declaration introduces one and only one name, for example using-
declaration for an enumeration does not introduce any of its enumeration.
All restrictions on regular declaration of the same names, hiding, and overloading
rules apply to using-declaration
**/
#include <iostream>
/// user defined
//#include "temp.h"

namespace A {
    int x;
}
namespace B {
    int i;
    struct g {};
    struct x {};
    void f(int);
    void f(double);
    void g(char);  // okay: function name g hides struct g
}

void B::f(int){}
void B::g(char){}
void B::f(double){}


void func(){
    int i;          // okay
//    using B::i;     // error: i declared twice

    void f(char);
    using B::f;     // okay f(char), f(double), f(int) are overloads
    f(2.2);         // call B::f(double)

    using B::g;     // struct g and g(char)
    g('a');         // calls B::g(char)
    struct g g1;    // declares g1 to have type struct B::g

    using B::x;     // struct B::x shows
    using A::x;     // int x shows and struct x hides
    x = 100;        // assigns to A::x
    struct x x1;    // declares x1 to have type struct B::x
}

int main(){

}













