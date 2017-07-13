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

// default template argument

// Default template argument are specified in the parameter lists after the = sign.
// Defaults can be specified for any kind of template parameter (type, non-type, or template)
// but not to parameter pack

// note: If the default is specified fo template parameter of a primary class template, each
// subsequent template parameter must have a default argument, expect the very last one may be
// a template parameter back.
//
// Default parameter are not allowed:
//  > in the out-of-class definition of a member template
//  > in friend class template declaration
//  > in any function template declaration or definition

template<typename T1, typename T2=int> class A;
template<typename T1=int, typename T2> class A;
// the above is the same as the following:
template<typename T1=int, typename T2=int> class A;

// the same parameter cannot be given default arguments twice in the same scope
template<typename T=float> class B:
template<typename T=float> class B{}


// class template with a type template parameter itself with a default
template<typename T=float> struct C{};

// template template parameter T has a parameter list, which
// consists of one type template parameter with a default
template<template<typename = float> typename T> struct D{
    void f();
    void g();
};
// out-of body member function template definition
template<template<typename TT> class T> void D<T>::f(){
    T<> t;  // error, TT has no default in scope
}
template<template<typename TT = char > class T > void A<T>::g() {
    T <> t; // okay, t is T<char>
}

// member access for the same names used in a default template parameter
// is checked at the declaration, not at the point of use:
class N {};
template<typename T> class M {
protected:
    typedef T TT;
};
template<typename U, typename V = typename U::TT> class S: public U {};
S<M<N>>* d; // error, M::TT is protected

int main(){}

