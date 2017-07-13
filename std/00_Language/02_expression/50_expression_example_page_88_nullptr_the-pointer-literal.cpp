/**

/// Expression
/// string literal
/// null, the pointer literal

The keyword 'nullptr' denote the pointer literal. It is a pr-value of the
std::nullptr_t. There exist implicit conversion form nullptr ot null pointer
value of any pointer type and any pointer to member type. Similar conversions
exist for any null pointer constant, which includes values of type std::nullptr_t
as well as the macro NULL.



**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

template<class F, class A>
void Fwd (F f, A a){
    f(a);
}
void g(int* i){
    std::cout<<"Function g was called\n";
}
int main(){
    g(NULL);            // fine
    g(0);               // fine
    Fwd(g,nullptr);     // fine

    // Error:
//    Fwd(g,0);

    // Error: no function g(int)
//    Fwd(g,NULL);
}













