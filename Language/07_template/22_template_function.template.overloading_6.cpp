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
// to compile a call to a function template, the compiler has to decide
// between non-template overloading, template overloading, and the
// specialization of the template overloading

template<class T> void f(T);        // #1:  template overloading
template<class T> void f(T*);       // #2:  template overloading
                  void f(float);    // #3:  non-template overloading
template<>        void f(int);      // #4:  specialization of #1

f('a');             // calls #1
f(new int(10));     // calls #2
f(1.1);             // calls #3
f(2);               // calls #4



template<class T> void f(T);        // #1:  overload for all type
template<>        void f(int*);     // #2:  specialization of #1 for pointer to int
template<class T> void f(T*);       // #3:  overload for all pointer type

f(new int(0));      // calls #3, even though specialization of #1 would be a prefect match
                    //
                    //
                    // Perhaps, c++ is crazy ... it should select #2 not #3





int main(){ return 0; }

