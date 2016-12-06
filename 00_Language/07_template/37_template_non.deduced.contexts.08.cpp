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
#include <typeinfo>
/// 05 template argument deduction
/**
**/
//  Non-deduced Contexts
// P means: Parameter
// A means: Argument
//
//  08  the template parameter list that appears within the parameter P,
//      and which includes a pack expression that is not at the very end
//      of the template parameter list.
template<int...> struct T{}

template<int... Ts1, int N, int... Ts2>
void good(const T<N, Ts1...>& arg1, const T<N, Ts2...>& ){}

template<int... Ts1, int N, int... Ts2>
void bad ( const T<Ts1..., N>& arg1, const T<Ts2..., N>&){}

T<1,2>      t1;
T<1,-1,0>   t2;

good(t1,t2);    // P1 = const T<N, Ts1...>&     A1 = T<1,2>     deduces N=1,    Ts1=[2]
                // P2 = const T<N, Ts2...>&     A2 = T<1,-1,0>  deduced N=1,    Ts2=[-1,0]

bad(t1,t2);     // P1 = const T<Ts1... , N>&    A1 = T<1,2>     <Ts1... , N> is non-deduced
                // P1 = const T<Ts1... , N>&    A1 = T<1,-1,0>     <Ts1... , N> is non-deduced


int main(){
return 0; }

