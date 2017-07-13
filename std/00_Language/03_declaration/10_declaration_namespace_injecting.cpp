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

namespace A {
    int i;
}
namespace B {
    int i;
    int j;
    namespace C {
        namespace D {
            using namespace A;      // All name from A injected into global namespace
            int j;
            int k;
            int a = i;              // i is belonging to B::i because A::i is hidden by B::i
        }
        using namespace D;          // All names form D are injected into C
                                    // All names form A are injected into global namespace
        int k = 90;                 // Okay to declare name identical to one introduced by a using
//        int l = k;                  // Ambiguous: C::k or D::k
        int m = i;                  // Okay: B::i hidden A::i
        int n = j;                  // Okay D::j hidden B::j
    }
}

int main(){

}













