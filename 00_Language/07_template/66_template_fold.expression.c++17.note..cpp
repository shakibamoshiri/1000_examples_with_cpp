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
#include <array>
template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };

/// 10 fold expression
// Reduces ( folds ) a parameter pack over a binary operator
// syntax:
//  ( pack operator ... )       : unary right fold
//  ( ... operator pack )       : unary left fold
//  ( pack operator ... init )  : binary right fold
//  ( init operator ... pack )  : binary left fold
//
//
/// Note:
//  When a unary fold is used with a pack expansion of length zero,
// only the following operators are allowed:
// Multiplication   *
// Addition         +
// Bitwise and      &
// Bitwise or       |
// logical and      &&
// logical or       ||
// comma operator   ,
//
//
// If the expression used as init ir as pack has an operator with
// precedence below cast at the top level, it can be parenthesized:
template<typename ... Args > int sum (Args ... args ) {
    // wrong syntax:
    // return ( args + ... + 1 * 2 )
    // operator with precedence below cast
    //
    // correct sytax:
    return ( args + ... + ( 1*2) ); // okay
}

int main(){}
