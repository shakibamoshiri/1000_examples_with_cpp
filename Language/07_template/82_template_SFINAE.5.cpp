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
// >    attempting to give an invalid type to a non-type template parameter
template < class T, T > struct S {};
template < class T > int f ( S<T, T()>* );
struct X {};
int i0 = f<X>(0);
// todo: needs to demonstrate overload resolution, not just failure
//
//
// > attempting to perform an invalid conversion in:
//      > in a template argument expression
//      > in an expression used in function declaration
template < class T, T* > int f ( int );
int i2 = f<int,1>(0);       // cannot convert 1 to int*
//
//
// >    attempting to create a function type with a parameter of type void
// >    attempting to create a function type which returns an array type or a function type
// >    attempting to create a cv-qualified function type
// >    attempting to create a function type with a parameter or return type that is an abstract class

int main(){



}

