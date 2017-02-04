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
//  type modifications: std::remove_reference

#include <iostream>
#include <typeinfo>


int main(){

    std::cout << std::is_same< int, std::remove_reference< int&& >::type >::value << '\n';  // true


}
/* output:



*/
