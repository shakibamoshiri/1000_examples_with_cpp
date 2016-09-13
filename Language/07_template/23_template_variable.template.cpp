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
/// 04 variable template
/**
A variable template defines a family of variable or static data template.

syntax:
template <parameter-list> variable-declaration


**/
template<class T> constexpr T pi = T(3.1415926535897932385);


int main(){
    std::cout<<pi<double><<std::endl;

    std::cout<<pi<float>*2<<std::endl;

    float pi2 = pi<float>;
    std::cout<<pi2<<std::endl;

return 0; }

