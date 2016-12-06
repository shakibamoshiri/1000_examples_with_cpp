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
/**
Template argument subsituation

**/
template<class T> void f(T t){}
template<class X> void g(const X x){}
template<class Z> void h(Z z, Z* zp){}
// two different function with the same type, but,
// within the function, t has different cv qualification
f<int>(1);          // function type is void(int), t is int
f<const int>(1);    // function type is void(int), t is const int

// two different function with the same type and the same x
// (pointers to these two function type are not equal,
//  and function-local statics would have different addresses )
g<int>(1);          // function type is void(int), x is const int
g<const int>(1);    // function type is void(int), x is const int

// only top-level cv-qualifier are dropped
h<const int(1,NULL);    // function type is void(int, const int*)
                        // z is const int, zp is const int*


int main(){ return 0; }

