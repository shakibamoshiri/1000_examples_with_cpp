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
// requirement used in the specialization of the standard library, see: library concepts.
// class template, function template, and non-template functions ( typically members of
// class template ) may be associated with a constraint, which specified the requirements
// on template argument, which can be used to select the most appropriate function overload
// and template specialization
//
// Constraint may also be used to limit automatic type deduction in variable declaration
// and function return types to only the types that specify specified requirement.
//
// Nmaes sets of such requirements are called 'concepts'. Each concepts is predicate, evaluated
// at compile time, and becomes a part of the interface of a template where it is used as a constraint
//
//
// Declaration of the concept "EqualityComparable", which is satisfied by
// and type T such that for values a and b of type T, the expression a == b
// compiles and its result is convertible to boolean.
template<typename T>
concept bool EqualityComparable = requires(T a, T b){
    { a == b } -> bool;
};


int main(){}

