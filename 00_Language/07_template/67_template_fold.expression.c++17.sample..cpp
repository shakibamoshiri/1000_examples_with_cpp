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
/// Example
template<typename... Args> void pritner (Args&&... args ) {
    ( std::cout<< ... << args ) std::endl;
}

int main(){
    pritner(1, 2, 3, "abc"); // output; 123abc
}
