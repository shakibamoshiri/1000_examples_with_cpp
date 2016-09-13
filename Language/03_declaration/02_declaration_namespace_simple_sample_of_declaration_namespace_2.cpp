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
    namespace V {       // original-namespace-definition for V
        void f(int);    // declaration of Q::V::f
    }
    void V::f(int t) {
        std::cout<<"Q::V::f(int) = "<<t<<std::endl;
    }                   // okay
//    void V::g() {}      // error: g() is not yet member of V
    namespace V {       // extension-namespace-definition for V
        void g();       // declaration of Q::V::g
    }
}
namespace R {           // not a enclosing namespace for Q
//    void Q::V::g() {} // error: cannot define Q::V::g inside R
}
void Q::V::g() {        // okay: global namespace enclosing Q
    std::cout<<__func__<<std::endl;
}
int main(){
    Q::V::f(100); // output : 100
    Q::V::g();    // output : g
}













