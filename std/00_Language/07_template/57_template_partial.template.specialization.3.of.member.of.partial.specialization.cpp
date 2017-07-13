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

template<typename T> void print(const T value){std::cerr<<value<<std::endl;}

template<class T> struct make { typedef T type; };


/// 07 partial template specialization
// Allows customizing class template for a given category of template argument
//
// The template parameter list and the template argument list of a member of a
// partial specialization must match the parameter list and the argument list of
// the partial specialization.
// Just like with members of primary template, they only need to be defined if need in the program.
// NOTE:
// Member of partial specialization are not related to the members of the primary template
// Explicit (full) specialization of a member of a partial specialization is declared the
// same way as an explicit specialization of the primary template.

template<class T, int I> struct A {     // primary template
    void f();                           // member declaration
};


template<class T, int I> void A<T, I>::f(){     // primary template member definition
    std::cout<<"A<T, I>::f"<<std::endl;
}

//  partial specialization
template<class T>           // omitted int
struct A<T,2> {
    void f();   // never definition
    void g();   // all three of these are not member of primary template above
    void h();
};
// void f, never

// member of partial specialization
template<class T>
void A<T,2>::g(){ print("this is the g"); }

// explicit (full) specialization
// of a member of partial specialization
//
template<>
void A<char,2>::h() { print("this is the h"); }

int main(){

    A<char, 0> a0;
    A<char, 2> a2;

    a0.f();     // okay, uses primary template's member definition
    a2.g();     // okay, uses partial specialization's member of definition
    a2.h();     // okay, used fully-specialized definition of the member of a partial specialization

    a2.f();     // error, no definition of f() in the partial specialization A<T, 2> ( the primary template is not used )

}
