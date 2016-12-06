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
/// NOTE:
// omitting <> entirely allows overload resolution to examine both
// template and non-template overload
int main(){
    f<double>(2);   // instantiation and calls f<double>(double)
    f<>('a');       // instantiation and calls f<char>(char)
    f(7);           // instantiation and calls f<int>(int)

    void (*ptr)(std::string) = f;   // instantiation of f<std::string>(std::string)

    ptr("std::string"); // calls though f<std::string>(std::string)
}

