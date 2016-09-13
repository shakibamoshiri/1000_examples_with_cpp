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

template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };


/// 05 template argument deduction
/**
auto return function

**/
auto f() { return 33; } // P = auto A = 33
                        // U is deduced to be int, the return type of f is int

// note:
//      if such function has multiple return statement, the declaration is preferred for each
//      return statement. All the resulting types must be the same and become the actual return type
//
//      if such function has no return statement 'A' is void() when deducing
//
//      the meaning of decltype(auto) placeholder in variable and function declaration does not
//      use template argument deduction


int main(){

return 0; }

