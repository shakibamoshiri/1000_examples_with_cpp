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
#include <vector>
#include <typeinfo>
/// 05 template argument deduction
/**
**/
//  Non-deduced Contexts
// P means: Parameter
// A means: Argument
//
//  07  The parameter P which is a parameter pack and does not occur at the end of the parameter list
template<class... Ts, class T> void f1 ( T n, Ts... args ){}
template<class... Ts, class T> void f1 ( Ts... args, T n ){}

int main(){

    f1(1,2,3,4);    // P1 = T,      A1 = T              T is deduced to be int
                    // P2 = Ts...   A2 = 2,A3=3,A4=4    T is deduced to be [int,int,int]
    f2(1,2,3,4);    // P1 = Ts..., non-deducible

return 0; }

