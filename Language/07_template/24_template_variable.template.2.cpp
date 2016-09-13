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
template<class T>
T circular_area(T t){
    return pi<T> * r * r;   // pi<T> is a variable template instantiation
}


// When used at class scope, variable template declares a static data member template
struct matrix_constants {
    template<class T>
    using paull = hermintain_matrix<T,2>;   // alias template

    template<class T>       // static data member template
    static constexpr paull<T> sigma1 = {{0,1},{1,0}};

    template<class T>
    static constexpr paull<T> sigma2 = {{0,-1i},{1i,0}};

    template<class T>
    static constexpr paull<T> sigma3 = {{1,0},{0,-1}};
};




int main(){
return 0; }

