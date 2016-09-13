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

namespace S {
    void s(int);
}
using S::s;         // ::s in now a synonym for A::f(int)
                    // so we can call it by s()
void S::s (int t) {
    std::cout<<"inside "<<__func__<<": "<<t<<std::endl;
}
namespace S {       // namespace extension
    void s(char);   // does not change what ::f means
}
// s(char) is not visible to global scope
// so s('s') is not true but s(2) is true
void one () {
    std::cout<<"only s(int) is accessible"<<std::endl;
    s(1);          // call s(int)
    s('s');         // call s(int), too
}
void S::s(char t){
    std::cout<<"inside "<<__func__<<": "<<t<<std::endl;
}
void two () {
    std::cout<<"both of s(int) and s(char) are accessible"<<std::endl;
    using S::s;     // Now both of them (s(int) , s(char) ) are visible
    s(2);
    s('s');
}
void f(int t){
    std::cout<<t<<std::endl;
}
int main(){
    // call f(int)
    f('f');

    // call one
    one();

    // invoke two
    two();

}













