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

namespace D {
    int d1;
    void f(char);
}
using namespace D;      // This syntax introduces all belongings of D name-space
                        // even those that after it, are declared.
int d1 = 0;             // Okay, no conflict with D::d1 when declaring
                        // because that d1 was declared inside D::
namespace E {
    int e;
    void f(int);
}

namespace D {           // namesapce extension
    // this namesapce has,
    // int d1;
    // void f(char);

    int d2;
    using namespace E;  // Transitive using-directive
    void f(int);
}

void D::f(int){}
void D::f(char){}

void f(){
//    d1++;       // Error: ambiguous ::d1 or D::d1, which one ?
    ::d1++;     // Okay
    D::d1++;    // Okay
    d2++;       // Okay, print to D::d2
    e++;        // Okay e is E::e due to transitive using
//    f(1);       // Error: ambiguous: D::f(int) or E::f(int) which one ?
    f('f');     // Okay, There is only one f(char) that is D::f(char)
}

int main(){

}













