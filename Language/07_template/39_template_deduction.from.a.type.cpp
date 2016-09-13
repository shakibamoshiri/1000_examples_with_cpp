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
// Deduction from a type
//
//  01  Template type argument cannot be deduced from the type of a non-type template argument
template<typename T, T i> void f(double d[10][i]){}
double v[10][20];
f(v);       // P = double[10][i]        A = double[10][20]
            // i can be deduced tot equal 20
            // but T cannot be deduced form the type of i

template<int i> class  A {};
template<short s> void f(A<s>){}    // the type of the non-type template parameter is short, but it need to be int
void g (){
    A<1> obj;   // the type of the non-type template parameter of obj is int
    f(obj);     // P = A<shorts>        A = A<(int)1>       Error, deduced non-type template argument
                // does not have the same type as its corresponding template argument
    f<1>(obj);  // okay, the template argument is deduced,
                // this calls f<(short)1>(A<(short)1>)
}

//  02  Template type parameter cannot be deduced form the type of a function default argument
template<typename T> void f(T=3, T,9);
void g(){
    f(1);       // okay,    calls f<int>(3,9)
    f();        // error,   cannot deduce T
    f<int>():   // okay,    calls f<int>(3,9)
}

//  03  Deduction of template parameter can use the type used in the tmeplate
//      specialization used in the function call
template<template<typename> class X> struct A{};        // A is a template with a TT parameter
template<template<typename> class TT> void f(A<TT>){}
A<B> ab;
f(ab);      // P = A<TT>        A = A<B>        this deduces TT=B so calls f(A<B>)




int main(){
return 0; }

