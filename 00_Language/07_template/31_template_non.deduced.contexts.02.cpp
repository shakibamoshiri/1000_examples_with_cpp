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
/// 05 template argument deduction
/**

**/
//  Non-deduced Contexts
//  02  the expression of a decltype-specifier
template<typename T> void f(decltype(std::declval<T>()) arg);
int n, f<int*>(n);  // P = decltype(*declval<T>()), A = int. T is not deducible




int main(){
return 0; }

