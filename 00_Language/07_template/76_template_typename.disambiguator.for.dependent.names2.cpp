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

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
//
//
//
//
/// The template disambiguator for dependent names
// The keyword 'typename' may only by used in this way before qualified name ( e.g. T::x ),
// but the name need not be dependent.
// Usual qualified name lookup is used for the identifier prefixed by 'typename'.
// Unlike the case with elaborated specifier, the lookup do not change despite the qualifier:
//

struct A {          // A has a nested variable X and a nested type X
    struct X {};
    int X;
};

struct B {
    struct X {};    // B has a nested type struct X
};
template<class T> void f( T t ) {
    typename T::X x;
}
void test () {
    A a;
    B b;
    f(a);           // okay, instantiation f<B>, T::X refers to B::X
    f(b);           // error, cannot instantiate f<A>
    // because qualified name lookup for A::X finds the data member
}
//
/// Note
// The keyword 'typename' must only be used in template declaration and
// definition and only in context in which dependent names can be used.
// This excludes explicit specialization declaration and explicit
// instantiation declaration
//
// The keyword 'typename' can be used even outside of template


int main(){
    typedef typename std::vector<T>::const_iterator it_t;   // okay in c++11
    typename std::vector<int> v;    // also okay in c++11

    // in the main site; it has said , okay
    // see: reference/en/cpp/language/dependent_name.html
    //
    // but complier says;
    // error: ‘T’ was not declared in this scope
}
