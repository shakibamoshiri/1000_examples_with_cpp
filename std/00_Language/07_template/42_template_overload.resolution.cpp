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
overload resolution

Template argument deduction is used during overload resolution,
when generating specializations from a candidate template function.
P and A are the same as in a regular function call


**/



std::string s;
std::getline(std::cin, s);
// "std::getline" names 4 function templates,
// 2 of which are candidate functions (correct number of parameters)
// 1st candidate template:
// P1 = std::basic_istream<CharT,Traits>&, A1 = std::cin
// P2 = std::basic_string<CharT,Traits,Allocator>&, A2 = s
// deduction determines the type template parameters CharT, Traits, and Allocator
// specialization std::getline<char, std::char_traits<char>, std::allocator<char>>
// 2nd candidate template:
// P1 = std::basic_istream<CharT,Traits>&&, A1 = std::cin
// P2 = std::basic_string<CharT,Traits,Allocator>&, A2 = s
// deduction determines the type template parameters CharT, Traits, and Allocator
// specialization std::getline<char, std::char_traits<char>, std::allocator<char>>
// overload resolution ranks reference binding from lvalue std::cin and picks
// the first of the two candidate specializations

int main(){
return 0; }

