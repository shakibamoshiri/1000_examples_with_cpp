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

/// 12 SFINAE ( Subsituation Failure Is Not An Error )
// This rule applies during overload resolution of function template:
// When sub-situating the deduced type for the template parameter fails,
// the specialization is discarded form the overload set instead of causing
// a compile error.
// This feature is used in template meta-programming. for more detail read main site: en.cppreference.com
//
//
/// Expression SFINAE
// the following expression errors are SFINAE errors:
// >    ill-formated expression used in a template parameter type
// >    ill-formated expression used in the function type
struct X {};
struct Y { Y((X){} };   // X is convertible to Y

template < class T > auto f ( T t1, T t2 ) > decltype ( t1 + t2 );  // overload #1
X f ( Y, Y );                                                       // overload #2

X x1, x2;
X x3 = f(x1, x2);   // deduction fails on #1 ( expression x1 + x2 is ill-formated )
                    // only #2 is in the overload set, and is called.

int main(){}

