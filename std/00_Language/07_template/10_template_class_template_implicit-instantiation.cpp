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
/// 02 class template
/*
A class template defines a family of classes.
syntax:
1. template<parameter-list> class-declaration
2. extern template<parameter-list> class-declaration

A class template by itself is not a type. In order for any code to appear, a template
must bu instantiated. The template is instantiated by the compiler.

Explicit Instantiation
1. template class name <argument-list>;
2. export template class name <argument-list>;
1. Explicit instantiation definition
2. Explicit instantiation declaration
    It is possible with class, struct and union
    It is only allowed to appear once in the entire program
    It can only appear in the enclosing namespace of the template,
        unless it used qualified-id
*/
template<class T> struct Z{
    void f(){}
    void g();   // never defined
};
template struct Z<double>;      // explicit instantiation of Z<double>
Z<int>  a;                      // implicit instantiation of Z<int>
Z<char>* p;                     // nothing is instantiation here
p->f();                         // implicit instantiation of Z<char> and Z<char>::f() occurs here
// Z<char>::g() is never needed and never instantiated: it does not have to be defined

int main(){}

