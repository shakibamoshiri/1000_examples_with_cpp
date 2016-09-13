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
/// 05 template argument deduction
/**
In order to instantiate a function template, every template argument must be known,
but not every template argument has to be specified, like before: see file 15

template<typename To, typename From> To convert(From f){}
void f(float argc){
    convert<int>(argc);             // calls convert<int,float>(float)
    convert<float>(argc);           // calls convert<float,float>(float)
    int (*ptr)(float)=convert;      // instantiation convert<int,float>(float)
    /// one type sticks on To       : convert<int> sticks to To
    /// another sticks on From      : convert<???>(float) sticks to From
}

**/
template<class T, int N> void h(const T(&)[N]){}
h({1,2,3});     // T deduced to int, N deduced to 3


template<class T> void j(T const (&)[3]){}
j({43});        // T deduced to int, array bound is not a parameter, not considered


struct Aggr {int i; int j;};
template<int N> void k(Aggr const (&)[N]){}
k({1,2,3});         // error, deduction fails, no conversion form int to Aggr
k({{1},{2},{3}});   // okay, N deduces to 3


template<int M, int N> void m(int const(&)[M][N]){}
m(({{1,2},{3,4}});  // M and N both deduced to 2

template<class T, int N> void n(T const (&)[N], T){}
n({{1},{2},{3}},Aggr());    // okay, T is Aggr, N is 3


int main(){
return 0; }

