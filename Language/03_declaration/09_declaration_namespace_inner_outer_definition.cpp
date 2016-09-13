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


**/
#include <iostream>
/// user defined
//#include "temp.h"

namespace X {
    namespace Y {
        void g();       // declares, but does not define X::Y::g()
    }
    using Y::g;
//    void g();           // error: attempt to declare X::g which conflicts with X::Y::g
}

int main(){

}













