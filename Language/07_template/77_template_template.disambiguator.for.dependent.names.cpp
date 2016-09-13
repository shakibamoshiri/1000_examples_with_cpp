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
template<typename T> struct D {
    template<typename U>  void func (){}
};
template<typename T> void g(){
    D<T> d;
//    d.f<T>();   // error, < parsed as less than operator
    d.template func<T>();
}
template<typename T,typename U>
void f2(){
    D<T> d;
//    d.func<U>();    // error, same as above
    d.template func<U>();
    // also
    // T::template func<U>();
}

// The keyword 'template' may only be used in this way after operator '::' ( scope resolution ),
// '->' ( member access through pointer ) and '.' ( member access ), the following are all valid examples:
//  T::template f<D>();
//  d.template  f<D>();
//  this->template f<D>();
//  typename T::template iterator<int>::value_type v;
//
//
// Even if the name to the left of :: refers to a namespace, the template disambiguator is allowed:
template<typename> struct S {};
::template S<void> s;   // allowed but unnecessary


int main(){
}
