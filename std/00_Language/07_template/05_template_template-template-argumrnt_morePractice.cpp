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

// A template argument for a template template parameter must be an
// id-expression which names a class template or a template alias.
template<typename T> struct A  { int x;};
template<typename T> struct A2  { const char* x;};
template<typename T> struct A3  { T x;};

template<template<typename> class U> struct B{
    U<int> u;
    U<const char*> str;
    // so we can have any type
    U<char> ch;
    U<float> flo;
    U<double> dou;
    // or
    U<int (*)()> pf;

};

int print(){return 134;}

int main(){
    A<int> a{1};
    std::cout<<a.x<<std::endl;

    B<A> b;         // using struct A, through struct B
    b.u.x = 2;
    std::cout<<b.u.x<<std::endl;

    B<A2> b2;
    b2.u.x = "how are you today?";
    std::cout<<b2.u.x<<std::endl;

    B<A3> b3;
    b3.u.x = 10;
    b3.str.x = "I am fine, how about you?";
    std::cout<<b3.u.x<<' '<<b3.str.x<<std::endl;

    // error, print is not a type
    // B<print> p2;

    /// Note:
    // So we can use a template template to more type flexible
}
