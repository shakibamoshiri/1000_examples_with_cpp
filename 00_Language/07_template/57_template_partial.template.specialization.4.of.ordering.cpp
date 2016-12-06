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
// partial ordering
//
// The function template are then ranked as if for function template overloading
template<int I, int J, class T> struct X {};    // primary
template<int I, int J>          struct X <I, J, int> {
    static const int s = 1;
};                                              // partial specialization #1
// fictitious function template for #1 is:
// template<int I, int J> void (X<I, J, int>);  #A

template<int I>                 struct X <I, I, int> {
    static const int s = 2;
};                                              // partial specialization #2
// fictitious function template for #2 is:
// template<int I> void f(X<I, I, int>);        #B


int main(){

    X<2,2,int> x;       // both #1 and #2 match
    // partial ordering for function template:
    //
    // #A from #B: void(X<I, J, int>) form void (X<U1, U2, int>):   deduction okay
    // #B form #A: void(X<I, I, int>) form void (X<U1, U2, int>):   deduction fails
    // #B is more specialized
    // #2 is the specialization that is instantiated
    std::cout<<x.s<<std::endl;  // output is 2

}
