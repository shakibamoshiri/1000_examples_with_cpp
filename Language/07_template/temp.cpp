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


/// 11 SFINAE ( Subsituation Failure Is Not An Error )
// This rule applies during overload resolution of function template:
// When sub-situating the deduced type for the template parameter fails,
// the specialization is discarded form the overload set instead of causing
// a compile error.
// This feature is used in template meta-programming. for more detail read main site: en.cppreference.com
//
//
/// Library support
// read main site
//
//
/// Alternatives
// read main site
//
//
/// Examples
// A common idiom is to use expression SFINAE on the return type, where the
// expression uses the comma operator, whose left sub-expression is the one
// that is being examined ( cast to void to ensure the user-defined operator
// comma on the returned type is not selected ), and the right sub-expression
// has the type that the function is supported to return.

int main(){}

