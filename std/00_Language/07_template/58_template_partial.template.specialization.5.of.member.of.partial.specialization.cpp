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
#include <typeinfo>
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
//
// If a partial specialization of the member template is explicitly specialized for a given
// ( implicit ) specialization of the enclosing class template, the primary member template and
// its other partial specialization are still considered for this specialization at the enclosing class template

template<class T> struct A {                  // enclosing class template
    template<class T2> struct B {};         // primary member template
    template<class T2> struct B<T2*> {};    // partial specialization of member template
};
template<>
template<class T2> struct A<short>::B {};   // full specialization of primary member template
                                            // will ignore the partial
A<char>::B<int*> abcip;     // uses partial specialization T2 = int
A<short>::B<int*> absip;    // uses full specialization of the primary ( ignores partial )
A<char>::B<int> abci;       // uses primary


int main(){

}
