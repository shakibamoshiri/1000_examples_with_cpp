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
// Sub-situation proceed in lexical order and stops when a failure is encountered
template<typename SomeType> struct inner_type { typedef typename SomeType::type type; };
template< class T,
        class = typename T::type,                       // SFINAE failure if T has no member type
        class U = inner_type<T>::type > void f(int);    // hard error if T hos no member type ( guaranteed to not occur as of c++14 )
