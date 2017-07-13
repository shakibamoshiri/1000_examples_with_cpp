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
/// 04 variable template
/**
A variable template defines a family of variable or static data template.

syntax:
template <parameter-list> variable-declaration


**/

struct limits {
    template<typename T>
    static const T min;     // declaration of a static data member template
};
template<typename T>
const T limits::min = {};   // definition of a static data member function

template<class T>
class X {
    static T s;             // declaration of a non-template static data member of a class template
};
template<class T>
T X<T>::s=0;                // definition of a non-template static data member of a class template

/// NOTe: variable template cannot be used a s template tempalte parameter.


int main(){
return 0; }

