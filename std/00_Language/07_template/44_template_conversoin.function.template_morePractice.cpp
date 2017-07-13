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
 struct B {
     int i = 99;
     template<typename T> operator T(){ return i; }
     // this syntax is useful for does not allow to conversion between type and data member if class
 };
B b;
int i = b;
char c = b;
float f = b;
const int ci = b;
const int& ri = b;
// wrong:
// int* pi = &b;

int main(){

    print(i);
    print(c);
    print(f);
    print(ci);
    print(ri);


return 0; }

