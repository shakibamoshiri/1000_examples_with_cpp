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
//  std::nullptr_t

#include <iostream>
#include <utility>

void f1( int* ){ puts( "It is a pointer to integer type" ); }
void f2( std::nullptr_t ){ puts( "It is a nullptr type" ); }

int main(){

    int number = 10;
    int* ptr = &number;

    f1( ptr );
    f2( nullptr );

}
/* output:


*/
