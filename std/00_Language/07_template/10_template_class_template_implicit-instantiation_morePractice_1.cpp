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
/*

*/
template<class T> struct Z{
    void f(){}
    void g();   // never defined
};
template<> struct Z<double> {
    Z(){
        std::cout<<"double type"<<std::endl;
    }
};

int main(){
    Z<int> i;
    Z<double> d;
}

