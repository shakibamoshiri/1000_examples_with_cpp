/**

/// Expression
/// operator overloading
/// function call operator
When a user-defined overloaded the function call operator, operator(),
it becomes a FunctionObject type. Many standard algorithm, from std::sort
to std::accumulate accept object of such types to customize behavior. There
are no particularly notable canonical forms of operator(), but to illustrate
the usage.

**/
#include <iostream>
#include <string>
#include <array>
/// user defined
//#include "temp.h"
struct X {
    int data;
    X () : data(20){}
    void operator()(const int t){this->data+=t;}
};
int main(){
    X x; /// data = 20
    x(10); /// data += 10
    std::cout<<x.data; /// data  = 30
}













