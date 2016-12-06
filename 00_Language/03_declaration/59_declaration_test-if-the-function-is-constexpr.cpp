/**
///

**/

#include <iostream>
#include <string>


constexpr int f();
constexpr bool b1 = noexcept(f());

constexpr int f(){return 0;}
constexpr bool b2 = noexcept (f());

int main(){

    // Because 'noexcept' operator always return 'true' for constant expression
    // if can be used to check if a particular invocation of a constant expression
    // function takes  the constant expression branch
    std::cout<<b1<< ' '<<b2; // 0 1



}









