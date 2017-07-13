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
Non-deduced Context

**/
//  01  The nested-name-specific ( everything to the left of the scope resolution operator::)
//      of a type that was specified using a qualified-id:
//
// the identity template, often used to execute specific argument form deduction
template<typename T> struct indentity { typedef T type; };
template<typename T>
void bad (std::vector<T> x, T value = 1);

template<typename T>
void good (std::vector<T> x, typename indentity<T>::type value=1);

std::vector<std::complex<double>> x;
bad(x, 1.2);        // P1 = std::vector<T>      A1 = std::vector<std::complex<double>>
                    // P1/A1 deduction determines T = std::complex<double>
                    // P2 = T,                  A2 = double
                    // P2 / A2 deduction determines T = double -- Error
good(x, 1.2);       // P1/A1 deduces T = std::complex<double>
                    // P2 = identity<T>::type,  T is to the left of ::, non-deduced


int main(){
return 0; }

