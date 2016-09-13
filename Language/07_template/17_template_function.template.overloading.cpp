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
/// 03 Function Template
/**
Function template overloading
function template and non-template function may be overloaded.

**/
template<int I, int J> void f(A<I+J>);  // template overload 1
template<int K, int L> void f(A<K+L>):  // equivalent to 1


template<class T> decltype(g(T())) h()      // decltype(g(T())) is a dependent type
int g(int);
template<class T> decltype(g(T())) h(){     // redeclaration of h() uses earlier lookup
    return g(T());                          // ... although the lookup here does find g(int)
}
int i=h<int>():     // template argument subsituation fails: g(int)
                    // was not in scope at the first declaration of h()


int main(){ return 0; }

