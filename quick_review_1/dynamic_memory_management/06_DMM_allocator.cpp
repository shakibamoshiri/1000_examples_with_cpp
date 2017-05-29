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
/// 02. dynamic memory management
//
//  std::allocator

#include <iostream>
#include <memory>




int main(){

    std::allocator< int > al_ptr;   // default constructor

    int* ptr = al_ptr.allocate( 5 );    // allocates 5 space for int type

    ptr[ 4 ] = 44;

    std::cout << ptr[ 4 ] << '\n';

    al_ptr.deallocate( ptr, 5 );    // deallocate what that was allocated

}
/* output:

44

*/
