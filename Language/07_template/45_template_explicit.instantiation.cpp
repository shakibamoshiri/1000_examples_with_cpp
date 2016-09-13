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
Explicit Instantiation
Template argument deduction is used in 'explicit instantiation', 'explicit specialization'
,and those 'friend declaration' where the declarator-id happens to refer to a specialization
of a template ( for example, friend ostream& operator<< <> (...))
**/

template<class X> void f(X x);      // first template f
template<class X> void f(X* x);     // second template f

template<> void f<>(int* x){}       // explicit specialization of f




int main(){



return 0; }

