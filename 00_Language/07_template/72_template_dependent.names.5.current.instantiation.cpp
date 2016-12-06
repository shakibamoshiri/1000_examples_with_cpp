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
template<class T> class A {
    A* p1;          // A is the current instantiation
    A<T>* p2;       // A<T> is the current instantiation
    ::A<T>* p3;     // ::A<T> is the current instantiation
    A<T*> p4;       // A<T*> is not the current instantiation

    class B {
        B* p1;                  // B is the current instantiation
        A<T>::B* p2:            // A<T>::B is not the current instantiation
        typename A<T*>::B*;     // A<T*>::B is not the current instantiation
    };
};

template<class T> class A<T*> {     // specialization
    A<T*>* p1;      // A<T*> is the current instantiation
    A<T>* p2;       // A<T> is not the current instantiation
};

template<int I> struct B {
    static const int my_I = I;
    static const int my_I2 = I+0;
    static const int my_I3 = my_I;

    B<my_I>* b1;        // B<my_I> is the current instantiation
    B<my_I2>* b2;       // B<my_I2> is not the current instantiation
    B<my_I3>* b3;       // B<my_I3> is the current instantiation
};
