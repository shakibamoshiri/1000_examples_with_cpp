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
//  runtime type identification
//  std::type_info

#include <iostream>
#include <typeinfo>

class A {};

struct B {};

int main(){

    std::cout << typeid( A ).name() << '\n';
    std::cout << typeid( B ).name() << '\n';
    std::cout << typeid( int ).name() << '\n';

    puts( "----------------" );

    int number = 0;
    std::cout << ( typeid( int ) == typeid( number ) ? "okay both are the same" : "no, not the same" ) << '\n';
    std::cout << ( typeid( A ) == typeid( B ) ? "okay both are the same" : "no, not the same" ) << '\n';

}
/* output:

1A
1B
i
----------------
okay both are the same
no, not the same

*/
