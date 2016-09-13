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
// more specialization
template<class T> void f(T);            // #1
template<class T> void f(T*, int=1);    // #2
int* p;
f(p);       // calls #2 (T* is more specialized than T)

template<class T> void f(T);            // #1
template<class T> void f(T*, ... );     // #2
int* p;
f(p);       // calls #2 (T* is more specialized than T)

template<class T            > void f(T, T  = T());      // #1
template<class T, class... U> void f(T, U...);          // #2
f(1);   //error, ambiguous-



int main(){ return 0; }

