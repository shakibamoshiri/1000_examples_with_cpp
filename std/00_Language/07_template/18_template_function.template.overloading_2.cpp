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

If a function contains declaration of function template that are functionally
equivalent but, not equivalent, the program is ill-formated; no diagnostic is required
**/

// equivalent:
template<int I> void f(A<I>,A<I+10>);   // overload #1
template<int I> void f(A<I>,A<I+10>);   // redeclaration of overload #1

// not equivalent:
template<int I> void f(A<I>, A<I+10>);  // overload #1
template<int I> void f(A<I>, A<I+11>);  // overload #2

// functionally-equivalent but not equivalent
// This program is ill-formated, no diagnostic required



int main(){ return 0; }

