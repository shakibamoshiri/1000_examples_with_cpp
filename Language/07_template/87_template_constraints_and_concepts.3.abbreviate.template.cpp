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


/// 13 constraints and concepts
//
//
//
/// Abbreviated template
// If one or more placeholder appears in a function parameter list,
// the function declaration is actually a function template declaration,
// whose template parameter list includes one invented parameter for
// every unique placeholder, on order of appearance.
//
// short form
void g1 (const EqualityComparable*, Incrementable& );

// long form
template<EqualityComparable T, Incrementable U> void g1 (const T*, U&);

// longer form
template<typename T, typename U>
void g1 ( const T*, U&) requires EqualityComparable<T> && Incrementable<U>;

// or

void f2 ( std::vector<auto*>...);
// long form
template<typename ... T> void f2 ( std::vector<T*>...);

void f3 ( auto ( (auto::*)(auto));
// long form
template<typename T, typename U, typename V> void f3 ( T (U::*)(V));

//
//
//
// All placeholders introduced by equivalent constrained type specifier
// have the same invented template parameter. However, each unconstrained
// specifier ( auto ) always introduces a different template parameter.
// ( it means three 'auto' == three parameter like, T , U , and V )
void f4 ( Comparable a, Comparable* b);
// long form
template<Comparable T> void f4 (T a, T* b);

void f5 (auto a, auto* b);
// long form
template<typename T, typename U> void f4 ( T a, U* b);

// Both function template and class template can be declared using a
// 'template introduction', which has the syntax:
/** concept-name { parameter-list ( optional ) } */// in which case the keyword
// template is not needed.
EqualityComparable{T} class Foo;
// long form
template<EqualityComparable T> class Foo;
// longer form
template<typename T> requires EqualityComparable<T> clas Foo;


template<typename T, int N, typename ... Xs> concept bool Example = ... ;
Example{A, B, ...C} struct S1;
// long form
template<class A, int B, class ...C> requires Example<A,B,C> struct S1;

// for function template, template introduction can be combined with placeholders:
Sortable{T} void f{T, auto );
// long form
template<Sortable T, typename U> void f(T , U);
// alternative using only placeholders:
void f (Sortable , auto);
