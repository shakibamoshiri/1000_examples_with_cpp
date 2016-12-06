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

namespace Q {
    namespace V {
        // namespace Q::V since c++17 alternative to the above two defined within Q
        class C { void m();};   // C is a member of V and fully defined within V
                                // C::m is only declared
        void f();               // f is a member of V, but it is only declared here.
    }
    void V::f(){                // definition of V's member f outside of V
                                // f's enclosing namespace are still the global namespace, Q, and Q::V
        extern void h(int t);    // this declared ::Q::V::h

    }
    void V::C::m()              // definition of V::C::m outside of namespace ( and the class body )
    {}                          // enclosing namespaces are the global namespace, Q, and Q::V

}

int main(){
    Q::V::f();
}













