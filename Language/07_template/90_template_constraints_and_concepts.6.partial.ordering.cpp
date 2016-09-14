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
/// Constraints
// A constraint is sequence of logical operators that specifies requirements
// on template arguments. They can appear within requires-expression and
// directly as bodies of concept
// There are 9 types of constraints:
/*
01  conjunction
02  disjunction
03  predicate constraints
04  expression constraints ( only in a requires-expression )
05  type constraints ( only in a requires-expression )
06  implicit conversion constraints ( only in a requires-expression )
07  argument deduction constraints ( only in a requires-expression )
08  exception constraints ( only in a requires-expression )
09  parameterized constraints ( only in a requires-expression )
*/
/// Partial ordering of constraints
// see the main site

template<typename T> concept bool Decrementable = requires(T t) { --t; };
template<typename T> concept bool RevIterator   = Decrementable<T> && requires(T t) {*t;};

// RevIterator subsumes Decrementable, but not the other way around ( but not the opposite situation )
// RevIterator is more constrained as Decrementable

void f(Decrementable);  // #1
void f(RevIterator)     // #2

f(0);                   // int only satisfies Decrementable, selects #1
f((int*)0);             // int* satisfies both constraints, selects #2 as more constrained

void g(auto);           // #3 ( unconstrained )
void g(Decrementable);  // #4

g(true);                // bool does not satisfy Decrementable, selects #3
g(0);                   // int satisfies Decrementable, selects #4 because it it more constrained


int main(){}
