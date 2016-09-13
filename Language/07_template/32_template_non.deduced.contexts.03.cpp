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
//
//  03  A non-type template argument or an array bound in which a subexpression reference
//      a template parameter
template<std::size_t N> void f(std::array<int, 2*N> a):
std::array<int, 10> a;
f(a);       // P = std::array<int, 2*N>,    "2*N" is non-deduced context, N cannot be deduced
            // note "f(std::array<int, N> a)" would be able to deduced N




int main(){
return 0; }

