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
//
//
// this overload is always in the set of overloads
// ellipsis ( means: ... ) parameter has the lowest ranking for overload resolution
void test(...){
    std::cout<<"Catch-all overload called"<<std::endl;
}
//
// this overload is added to the set of overloads if C  is a
// reference-to-class type and F is a member function pointer
template<class C, class F> auto test(C c,F f)
    -> decltype ( (void)(c.*f)(), void() ) {
        std::cout<<"Reference overload called"<<std::endl;
}
//
// this overload is added to the set of overloads if C  is a
// reference-to-class type and F is a member function pointer
template<class C,class F> auto test(C c,F f)
    -> decltype ( (void)(c->*f)(), void() ) {
        std::cout<<"Pointer overload called"<<std::endl;
}

struct X { void f(){} };

int main(){
    X x;
    test(x, &X::f);     // reference called
    test(&x, &X::f);    // pointer called
    test(43, 'd');      // catch-all
}



