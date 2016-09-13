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
/// Unknown specialization
// for more detail, see en.cppreference.com
//
//
template<typename T> struct Base {};

template<typename T> struct Derived : Base<T> {
    void f(){
        // Derived<T> refers to current instantiation
        // there is no 'unknown_type' is the current instantiation
        // but there is a dependent base ( Base<T> )
        // Transforms, unknown_type is a member of unknown specialization
        typename Derive<T>::unknown_type z;
    }
};
template<> struct Base<int> {   // this specialization provides it
    typedef int unknown_type;
};
//
// This classification allows the following errors to be detected at the
// point of template definition (rather than instantiation):
//
// If any template definition has a qualified name in which the qualifier
// refers to the current instantiation and the name is neither a member of
// current instantiation nor a member of unknown specialization, the program
// is ill-formed (no diagnostic required) even if the template is never instantiated.
//
template<class T> class A {
    typedef int type;
    void f(){
        A<T>::type i;           // okay, 'type' is a member of the current instantiation
        typename A<T>::other j; // Error
        // 'other' is not a member of current instantiation
        // and it is not a member of the unknown specialization
        // because A<T> ( which names the current instantiation )
        // has no dependent basses for 'other' to hide in.
    }
};
