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
// This page describes an experimental core language feature. For named type
// requirements used in the specification of the standard library, see library
// concepts
// Class templates, function templates, and non-template functions (typically
// members of class templates) may be associated with a constraint, which specifies
// the requirements on template arguments, which can be used to select the most
// appropriate function overloads and template specializations.
// Constraints may also be used to limit automatic type deduction in variable
// declarations and function return types to only the types that satisfy specified requirements.
// Named sets of such requirements are called concepts. Each concept is a predicate,
// evaluated at compile time, and becomes a part of the interface of a template where
// it is used as a constraint:
//
// Declaration of the concept "EqualityComparable", which is satisfied by
// any type T such that for values a and b of type T,
// the expression a==b compiles and its result is convertible to bool
template<typename T>
concept bool EqualityComparable = requires(T a, T b) {
    { a == b } -> bool;
};

void f(EqualityComparable&&); // declaration of a constrained function template
// template<typename T>
// void f(T&&) requires EqualityComparable<T>; // long form of the same

f("abc"s); // OK, std::string is EqualityComparable
f(std::use_facet<std::ctype<char>>(std::locale{})); // Error: not EqualityComparable

// violation of constraints are declared at compile time, early in the
// template instantiation process, which leads to easy to follow error messages.
std::list<int> l = { 3,-9,10 };
std::sort(l.begin(), l.end();
// typical complier diagnostic without concepts:
//      invalid operands to binary expression ( 'std::_list_iterator<int>' and
//                           std::__lg(__last - __first) * 2);
//                                     ~~~~~~ ^ ~~~~~~~
//      ... 50 lines of output ...
//
//      Typical compiler diagnostic with concepts:
//      error: cannot call std::sort with std::_List_iterator<int>
//      note:  concept RandomAccessIterator<std::_List_iterator<int>> was not satisfied

