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

// template template argument 2

template<typename T> struct eval;   // primary template
template<template<typename, typename...> class TT, typename T1, typename... Rest>
struct eval<TT<T1, Rest...>> {};    // partial specialization of eval

template<typename T1> struct A;
template<typename T1, typename T2> struct B;
template<int N> struct C;
template<typename T1, int N> struct D;
template<typename T1, typename T2, int N=14> struct E;

eval<A<int>> eA;        // okay, matches partial specialization of eval
eval<B<int, float> eB;  // okay, matches partial specialization of eval
eval<C<14> eC;          // error, c does not match TT in partial specialization because
                        // TT's first parameter is a type template parameter, while 14 does not name a type
eval<D<int, 17> eD;     // error, same as above: eC
eval<E<int, float> eE;  // error, E does not match TT in partial specialization, because E's third (default) parameter is a  non-type


int main(){}
