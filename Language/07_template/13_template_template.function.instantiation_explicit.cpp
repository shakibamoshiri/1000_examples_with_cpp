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
Function Template instantiation
A function template by itself is not a type, or function or any other entity.

Explicit instantiation:
1. template return-type-name <parameter-list> ( parameter-list ): like template void f<int>(){}
2. template return-type-name ( parameter-list )
3. extern template return-type-name <parameter-list> ( parameter-list )
4. extern template return-type-name ( parameter-list )

**/
template<typename T> void f(T t) { std::cout<<t<<std::endl; }
template void f<double>(double);   // instantiation f<double>(double)
template void f<>(char);           // instantiation f<char>(char)
template void f(int);              // instantiation f<int>(int)

/// Note:
// Explicit instantiation of a function template of or a member function
// of a class template cannot use 'inline' and 'constexpr'.


int main(){}

