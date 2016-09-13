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
//  05  The parameter P, whose A is a function or a set of overloads such that more
//      than one function matches P or no function matches P or the set of overloads
//      includes one or more function template:
template<typename T> void out ( const T& value ) { std::cout<<value; }
out("12345");       // P = const T&     A = const char[6] l-value,  T is deduced to be "char[6]"
out(std::endl);     // P = const T&     A = function template,      T is non-deducible, error



int main(){
return 0; }

