/*
    quick review:

    Language Support
        01. type support
        02. dynamic memory management
        03. error handling
        04. initializer-list
        05. variadic function
    **********************************

*/
/// 01. type support:
//
//  <type_traits>
//  primary type category

#include <iostream>
#include <typeinfo>

class A {};

struct B {};

int main(){

    std::cout << std::is_void< void >::value << '\n';   // 1
    std::cout << std::is_void< char >::value << '\n';   // 0
    std::cout << std::is_integral< int >::value << '\n';     // 1
    std::cout << std::is_class< A >::value << '\n';     // 1


}
/* output:



*/
