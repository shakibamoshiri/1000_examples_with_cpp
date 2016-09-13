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

void h(int){
    std::cout<<"::h(int) in the global scope"<<std::endl;
}
namespace A {
    class X {
        friend void f(X);           // A::f is a friend
        class Y {
            friend void g();        // A::g is a friend
            friend void h(int);     // A::h is a friend, no conflict with ::h
        };
    };
    // NOTE:
    // A::f, A::g and A::h are not visible to namespace scope
    // even though they are members of the namespace A

    X x;
    void g(){                       // definition of A::g
        f(x);                       // A::X::f is found through ADL
    }
    void f(X) {                     // definition of A::f
        std::cout<<"definition of A::f"<<std::endl;
    }
    void h(int) {                   // definition of A::h
        std::cout<<"definition of A::h"<<std::endl;
    }

    // So
    // A::f, A::g and A::h are now visible to namespace scope
    // and they are also friends of A::X and A::X::Y
}

int main(){
    A::X x;
    f(x);

    // error
    // b(10); b in which scope !!!
    // this is okay A::h(10)
    A::h(10);


    // class Y is private of class X
    // so this is error
    // A::X::Y y;


    // this is okay and call h function in global scope
    h(10);
}













