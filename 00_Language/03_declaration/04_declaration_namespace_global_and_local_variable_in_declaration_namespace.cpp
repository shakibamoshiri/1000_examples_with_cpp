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

// namepsave without name, it look like global scope
namespace {
    int i=1;          // define ::(unique)::i
}
// because i is global, so inside f function, we can increment it.
void f(){
    i++;            // increments ::(unique)::i
}
// This namespace had a name, so all things inside it, only will be member of A
namespace A {
    namespace {
        int i;      // A::(unique)::i
        int j;      // A::(unique)::j
    }
    void g() { i++; }   // A::(unique)::i++
}
using namespace A;  // introduces all names from A into global namespace
void h(){
//    i++             // error: ::(unique)::i and ::A::(unique)::i are both in scope
                    // which do you mean ?
    A::i++;         // okay, increment ::A::(unique)::i
    j++;            // okay, increment ::A::(unique)::j
}

int main(){

    // error: reference to ‘i’ is ambiguous
    // here are two i
    // std::cout<<::i<<std::endl;
    // we can not use i in the f function

    // this is okay
    ::A::i;

    // this is okay, too.
    int i = 2;
    std::cout<<i<<std::endl;
}













