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
/// 01 template parameter and template argument

// template template argument

template<typename T> struct B {
    T a;
    int b;

};
template<template<typename> class U> struct T {
    U<int> _int;
    U<const char*> _string;
};

int main(){
    T<B> t1;
    t1._int.a = 10;                 // okay
    t1._string.a = "_string.a";     // okay
    t1._int.b = 11;                 // okay, both type are int
    t1._string.b = "_string.b";     // error, conversion form 'const char*' to 'int'
}
