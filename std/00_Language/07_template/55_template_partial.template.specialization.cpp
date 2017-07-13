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


/// 07 partial template specialization
// Allows customizing class template for a given category of template argument

template<class T1, class T2, int I>
class A {};                 // primary template

template<class T, int I>
class A<T, T*, I> {};        // partial specialization where T2 is a pointer to T1

template<class T, class T2, int I>
class A<T*, T2, I> {};       // partial specialization where T1 is a pointer

template<class T>
class A<int, T*, 5> {};     // partial specialization where T1 is a int, T2 is a pointer and I is 5

template<class X, class T, int I>
class A<X, T*, I> {};        // partial specialization where T2 is a pointer

// Examples fo partial specialization in the standard library include std::unique_ptr,
// which has a partial specialization for array type.
