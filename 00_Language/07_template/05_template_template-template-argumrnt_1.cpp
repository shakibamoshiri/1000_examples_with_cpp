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
/// 01 template parameter and template argument

// template template argument

// A template argument for a template template parameter must be an
// id-expression which names a class template or a template alias.
template<typename T> struct A  { int x;};
template<class T> struct A<T*> { long x;};

// class template with a template template argument V
template<template<typename> class V> struct C {
    V<int> y;   // uses the primary
    V<int*> z;  // uses the partial specialization
};

C<A> c;     // c.y.x has type int, c.z.x has type long

int main(){}
