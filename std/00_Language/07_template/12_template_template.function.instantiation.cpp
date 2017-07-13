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

template<typename T> void f(T t) {
    std::cout<<__func__<<std::endl;
}

// Explicit instantiation
template<> void f(int) {
    std::cout<<"Explicit instantiation of int in f function"<<std::endl;
}
template void f<float>(float); // it is nothing to do, here.
// of class
template<class T> class B {};
template<> class B<int> {};     // needs <>

// of function
template<typename S> void s (){}
template<> void s<int>(){}



int main(){
    f('s'); // f
    f(0);   // Explicit instantiation of int in f function

    f(2.2); // call void f(T t) and output is: f
}

