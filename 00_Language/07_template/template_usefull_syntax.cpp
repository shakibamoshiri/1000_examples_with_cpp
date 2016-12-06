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


/// 05 template argument deduction
/**
**/

void func(int t){ print(t); }

int main(){
    make<int>::type one;
    one = 33;
    print(one);

    make<void(*)(int)>::type pf;
    pf = func;
    pf(33);

    // error: func is not a type
    // make<func>::type pf2;


return 0; }

