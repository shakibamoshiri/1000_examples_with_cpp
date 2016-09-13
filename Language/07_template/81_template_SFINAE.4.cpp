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
/// Type SFINAE
// >    attempting to create a pointer to reference
// >    attempting to create reference to void
// >    attempting to crate pinter to member of T, where T is not a class type
template < typename T> class is_class {
    typedef char yes[1];
    typedef char no [2];
    template < typename C > static yes& test ( int C::* );  // selected if C is a class type
    template < typename C > static no&  test ( ... );       // selected otherwise
public:
    static bool const value = sizeof ( test<T>(0) ) == sizeof(yes);
};

int main(){



}

