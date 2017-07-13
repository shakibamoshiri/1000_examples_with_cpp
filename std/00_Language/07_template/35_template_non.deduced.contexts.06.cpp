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
// P means: Parameter
// A means: Argument
//
//  06  The parameter P, whose A is a braced-initializer-list, but P is non-std::initializer_list or a reference to one.
template<class T> void f1(std::vector<T>);
f1({1,2,3});    // P = std::vector<T>,      A = {1,2,3}     this P is non-deduced context
                // error, T is non explicitly specified or deduced form another P/A

template<class T> void f2(std::vector<T>, T x);
f2({1,2,3},10);  // P1 = std::vector<T>      A1 = {1,2,3}    this P is non-deduced context
                // P2 = T                   A2 = int        this P/A pair deduces T = int



int main(){
return 0; }

