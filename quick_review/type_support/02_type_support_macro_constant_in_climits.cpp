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
//  macro constant in header <climits>
//  for more detail see the header limits.h

#include <iostream>
//#include <utility>
#include <climits>



int main(){

    std::cout << INT_MAX << '\n';
    std::cout << CHAR_MAX << '\n';

}
/* output:
2147483647
127

*/
