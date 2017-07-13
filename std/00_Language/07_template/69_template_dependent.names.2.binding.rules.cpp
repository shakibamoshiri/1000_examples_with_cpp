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
#include <array>

/// 10 Depending Name
// Inside the definition of a template ( both class-template and function-template ),
// the meaning of some constructs may differ form one instantiation to another. In
// particular types and expression may depend on types of type template parameter and
// value of non-type template parameter.
//
//
//
//
/// binding rule
// Non-dependent names are looked up and bound at the point of template definition.
// This binding holds even if at the point of template instantiation there is a better match:
void g ( double ) { std::cout<< "g(double)"<<std::endl; }

template<class T> struct S {
    void f() const { g(1); }    // g is a non-dependent name, bound now
};

void g (int ) { std::cout<<"g(int)"<<std::endl; }

int main() {
    g(1);   // call g(int)

    S<int> s;
    s.f();  // calls g(double)
}
