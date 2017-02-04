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
/// 04. initializer_list


#include <iostream>
#include <initializer_list>





int main(){

    std::initializer_list< int > ilist = { 1, 2, 3, 4, 5 };

    for( const int& i : ilist ){ std::cout << i << ' '; }

}
/* output:

1 2 3 4 5

*/
