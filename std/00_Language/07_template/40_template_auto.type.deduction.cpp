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
auto type deduction
Template argument deduction is used in declaration of variable,
when deducing the meaning of the auto specifier form the variable
initializer.

**/

const auto& x = 1+2;    // P = const U&,    A = 1+2
                        // same rules as for calling f(1+2) where f is:
                        // template<class U> void f(const U& u)
                        // U is deduced ot be int, and the type of x is const int&
auto l = {3};           // P = std::initializer_list<U>,    A = {3}
                        // U is deduced to be int, the type of l is std::initializer_list<int>
auto x2 = {3};          // x2 is std::initializer_list<int>
auto x3 {2,3};          // error, not a single element
auto x4 {3};            // x4 is int ( before it was std::initializer_list<int> )


int main(){

return 0; }

