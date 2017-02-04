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
//  Fixed width integer type
//  in the header <cstdint>

#include <iostream>
//#include <utility>
#include <cstdint>



int main(){

    std::cout << sizeof( int8_t ) << '\n';
    std::cout << sizeof( int16_t ) << '\n';

}
/* output:

1
2

*/
