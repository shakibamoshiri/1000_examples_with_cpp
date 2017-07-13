/*
Template:
    01 template parameter and template argument
    02 class template
    03 function template
    04 variable template
    05 template argument deduction
    06 explicit (full) template specialization
    07 partial template specialization
    08 parameter pack
    09 sizeof ... operator
    10 fold expression
    11 dependent names
    12 SFINAE
    13 constraints and concepts
*/
#include <iostream>
/// 03 Function Template
/*
A function template defines a family of function.

Syntax:
1. template<parameter-list> function-declaration
2. extern template<parameter-list> function-declaration

When placeholders ( either 'auto' or constrained placeholder ) appear in the
parameter list of a function declaration or of a function template declaration,
one invented template parameter for each placeholder is appended to the template
parameter list.
*/
void f(auto (auto::*)(auto));       // #1
template<typename A, typename B, typename C> void f(A (B::*) (C));  // same as #1

template<int N> void f(Array<auto,N>*);     // #2   ( assuming Array is a class template )
template<int N, typename T> void f(Array<T,N>*);    // same as #2

void g(const C1*, C1&);     // #3 ( assuming C1 and C2 are concept )
template<C1 T, C2 U> void g(const T*, U&);      // same as #3

int main(){}

