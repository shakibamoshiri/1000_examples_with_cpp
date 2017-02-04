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
//  type relationships

#include <iostream>
#include <typeinfo>
#include <cstdint>  // fixed integer type

class A {};

struct B {};

int main(){

    std::cout << std::is_same< int, int8_t >::value << '\n';    // false
    std::cout << std::is_same< int, char >::value << '\n';      // false
    std::cout << std::is_same< B, A >::value << '\n';           // false
    std::cout << std::is_same< A, A >::value << '\n';           // true
    std::cout << std::is_same< int, int32_t >::value << '\n';   // true


}
/* output:



*/
