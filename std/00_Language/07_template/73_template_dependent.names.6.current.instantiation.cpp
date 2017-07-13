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
/// Dependent type
// see en.cppreference.com
//
//
/// type-dependent expression
// see en.cppreference.com
//
//
/// value-dependent expression
// see en.cppreference.com
//
//
/// dependent name
// see en.cppreference.com
//
//
/// current instantiation
// Within a class template definition (include its member function and nested classes )
// some names may be deduced to refer to the current instantiation. This allows certain
// errors to be detected at the point of definition, rather than instantiation, and removes
// the requirement on the 'typename' and 'template' disambigutors for dependent names.
//
// Only the following name can be refer to the current instantiation
//
// in a class template definition
// a nested class, a member of class template, a member of a nested class,
// the injected-class-name of the template, the injected-class-name of a nested class
//
// in a primary class template definition or in the definition of its member:
// name of the class template followed by template argument list
// (or an equivalent alias template specialization) for the primary template where
// each argument is equivalent to its corresponding parameter. Note that if an
// expression is used as a non-type template argument (e.g. N+0 where N is the parameter),
// it does not name the current instantiation even if its value matches.
//
// in the definition of a nested class or class template:
// name of the nested class used as a member of the current instantiation
//
// in the definition of a partial specialization or of a member of a partial specialization:
// the name of the class template followed by template argument list for the partial
// specialization, where each argument is equivalent to its corresponding parameter
//
// NOTE:
// that a base class cab be the current instantiation if a nested class derived from its
// enclosing class template. Base classes that are dependent types are not current instantiation
// are dependent base classes
template<class T> struct A {
    typedef int M;
    struct B {
        typedef void M;
        struct C;   // forward declaration
    };
};
template<class T>
struct A<T>::B::C : A<T> {  // inheritance
    M m;            // okay, A<T>::M
}
/*
A name is classified as a member of the current instantiation if it is

    an unqualified name that is found by unqualified lookup in the current
    instantiation or in its non-dependenent base.

    qualified name, if the qualifier (the name to the left of ::) names the current
    instantiation and lookup finds the name in the current instantiation or in its non-dependent base

    a name used in a class member access expression (y in x.y or xp->y), where the object
    expression (x or *xp) is the current instantiation and lookup finds the name in
    the current instantiation or in its non-dependent base
*/
template<class T> class A {
    static const int i = 5;
    int n1[i];              // i refers to a member of the current instantiation
    int n2[A::i];           // A::i refers to a member of the current instantiation
    int n3[A<T>::i];        // A<T>::i refers to a member of the current instantiation
    int f():                // forward declaration
};
template<class T> int A<T>::f() {
    return i;               // i refers to a member of the current instantiation
}
//
// member of the current instantiation may be both dependent and non-dependent
//
// If the lookup of a member of current instantiation gives a different result
// between the point of instantiation and the point of definition, the lookup is
// ambiguous. Note however that when a member name is used, it is not automatically
// converted to a class member access expression, only explicit member access expressions
// indicate members of current instantiation:
struct A { int m; };
struct B { int m; };

template<typename T> struct C: A, T {
    int f() { return this->m; }     // find A::m in the template definition context
    inf g() { return m; }           // find A::m is the template definition context
};

template int C<B>::f();             // error, finds both A::m and B::m
template int C<B>::g();             // okay, transformation to class member access syntax
                                    // does not occur in the template definition context
