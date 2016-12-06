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
Function template overloading
function template and non-template function may be overloaded.

**/

template<class X> void f(X a);          // first template f
template<class X> void f(X* a);         // first template f
template<> void f<>(int *a){}           // explicit specialization
// template argument deduction comes up with two candidate
// f<int*>(int*) and f<int>(int*)
// partial ordering selects f<int>(int*) as more specialization

int main(){ return 0; }

