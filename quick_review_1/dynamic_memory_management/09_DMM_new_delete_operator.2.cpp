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
//  low level memory management



#include <iostream>
#include <cstdlib>



void* operator new( std::size_t size ){
    std::cout << "global operator 'new' was called for single\n";
    return std::malloc( size );

}
void operator delete( void* ptr ){
    std::cout << "global operator delete was called for single\n";
    std::free( ptr );
}



void* operator new[]( std::size_t size ){
    std::cout << "global operator 'new' was called for array\n";
    return std::malloc( size );
}
void operator delete[]( void* ptr ){
    std::cout << "global operator delete was called for array\n";
    std::free( ptr );
}


int main(){

    int* arr = new int[ 4 ];
    arr[ 3 ] = 33;
    std::cout << arr[ 3 ] << '\n';
    delete [] arr;

}
/* output:

global operator 'new' was called for array
33
global operator delete was called for array

*/
