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
/// Concepts
// A concept is named set of requirement. The definition of a concept
// appears at namespce scope and had the form of a function template
// definition ( in which case it is called function concept ) of variable
// template definition ( in which case it is called variable concept ).
// The only different is that he keyword concept appears in the decl-specifier-seq:
//
// variable concept form the standard library ( Ranges TS )
template<class T> class U>
concept bool Derived = std::is_base_of<U, T::value;

// function concept form the standard library ( Ranges TS )
template<class T>
concept bool EqualityComparable() {
    return requires (T a, T b) { { a == b} -> Boolean; { a != b } -> Boolean; };
}
// for more detail read: en.cppreference.com
//
//
// Concepts cannot recursively refer to themselves in the body of
// the function or in the initializer of a variable:
template<typename T> concept bool F() { return F<typename T::type(); }  // error
template<typename T> concept bool V() = V<T*>;                          // error

// Explicit instantiation, explicit specialization, or partial specialization
// of concept are not allowed.
// The meaning of the original definition of a constraint cannot be changed.
