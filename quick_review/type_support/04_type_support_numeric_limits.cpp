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
//  limits library

#include <iostream>
#include <limits>



int main(){

    std::cout << std::numeric_limits< int >::max() << '\n';
    std::cout << std::numeric_limits< float >::max() << '\n';
    std::cout << std::numeric_limits< long double >::max() << '\n';


}
/* output:

2147483647
3.40282e+38
1.18973e+4932
*/
