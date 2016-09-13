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
#include <iterator>
#include <utility>

/// 11 SFINAE ( Subsituation Failure Is Not An Error )
// This rule applies during overload resolution of function template:
// When sub-situating the deduced type for the template parameter fails,
// the specialization is discarded form the overload set instead of causing
// a compile error.
// This feature is used in template meta-programming. for more detail read main site: en.cppreference.com
//
//
/// Type SFINAE
// >    the type does not contain the specified member
// >    the specified member is not a type where a type is required
// >    the specified member is not a template where a template is required
// >    the specified member is not a non-type where a non-type is required
template<int I> struct X {};
template<template<class T> class> struct Z{};

template<class T> void f( typename T::Y*){}
template<class T> void g (X<T::N>*){}
template<class T> void h (Z<T::template TT>*){}

struct A {};
struct B { int Y; };
struct C { typedef int N; };
struct D { typedef int TT; };

struct B1 { typedef int Y; };
struct C1 { static const int N = 0; };
struct D1 {
    template<typename T>
    struct TT {};
};

int main(){

    // deduction fails in each of these cases:
    f<A>(0);    // A does not contain a member Y
    f<B>(0);    // The Y member of B is not a type
    g<C>(0);    // The member of C is not a non-type
    h<D>(0);    // the TT member of D is not a template

    // deduction succeeds in each of these cases:
    f<B1>(0);
    g<C1>(0);
    h<D1>(0);

}

