/**
/// Namespaces
///
///
Nampspaces provide a method for preventing name conflict in large project.
symbols declared inside a namespace block are placed in a name scope that
prevents them form being mistaken for identically-named symbols in other scopes.
Multiple namespace blocks with the same name are allowed. All declarations within
those blocks are declared in the named scope.

Syntax:

1   namespace ns_name { declaration }
2   inline namespace ns_name { declaration }
3   namespace { declaration }
4   ns_name::name
5   using namespace ns_name;
6   using ns_name::name;
7   namespace name = qualified-namespace;
8   namespace ns_name::name. since c++ 17

**/
#include <iostream>
/// user defined
//#include "temp.h"
void f(){
    std::cout<<"my name is: "<<__func__<<std::endl;
}
namespace A {
    void g();
}
void A::g(){
    std::cout<<"my name is: "<<__func__<<std::endl;
}
namespace X {
    using ::f;      // global f is new visible as ::X::f;
    using A::g;     // A::g is now visible as ::X::g
}
void h(){
    X::f();         // call ::f
    X::g();         // call A::g;
}
int main(){
    // calling f and A::g together
    h();

    // calling only f
    f();

    // calling only A::g
    A::g();

}













