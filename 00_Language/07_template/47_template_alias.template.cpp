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
Alias template

Alias template are never deduced.

**/
template<class T> struct Alloc {};
template<class T> using Vec = std::vector<T, Alloc<T>>;
Vec<int> v;

template<template<class, class> class TT> void g ( TT<int, Alloc<int>> ){}
g(v);   // okay, deduced TT = vector

template<template<class> class TT> void f ( TT<int> ){}
f(v);   // error, TT cannot be deduced as 'Vec' because Vec is an alias template



int main(){


return 0; }

