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
//
// The Argument List
//
// The following restrictions apply to the argument-list of partial template specialization
//
// 01   The argument list cannot be identical to the non-specialization argument list.
//      it must specialized something.
template<class T1, class T2, int I> class A{};      // primary template
template<class A,  class B,  int N> class<A,B,N>{}; // error, nothing specialized

// 02   Default argument cannot be appear in the argument lists

// 03   The specialization has to be more specialized than the primary template
template<int N, typename T1, typename... Ts> struct A;      // primary forward declaration
template<typename... Ts> struct A<0, Ts...> {};             // error, not more specialized

// 04   If any argument is a pack expansion, it must be the last argument in the list

// 05   Not-type argument expression cannot use the name of the template
//      except when it is exactly the same name of the template parameter
template<int I, int J> struct A {};             // primary
template<int I>        struct A<I+2, I*3>{};    // error
template<int I>        struct A<I, I> {};       // okay

// 06   non-type template argument cannot specialize a template parameter
//      whose type depends on a parameter of the specialization
template<class T, T t> struct C {};             // primary
template<class T>      sturct C<T, 1>{};        // error, type of the argument 1 is T, which depends on the parameter T
template<class T>        struct C<T, t>{};        // error,
template<class T t>      struct C<T, t>{};        // error,


template<int X, int (*array_ptr)[X]> class A {};    // primary
int array[5];
template<int X>  class A<X, &array> {};             // error,type of the argument &array, is int(*)[X] which depends on the parameter X













