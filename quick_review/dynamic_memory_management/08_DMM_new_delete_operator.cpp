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
    std::cout << "global operator 'new' was called\n";
    return std::malloc( size );
}
void operator delete( void* ptr ){
    std::cout << "global operator delete was called\n";
    std::free( ptr );
}


int main(){

    int* ptr = new int( 10 );   // an integer which its value equals to 10
    std::cout << *ptr << '\n';
    delete ptr;

    int* array_ptr = new int[ 10 ]; // returns array of int. (guaranteed to call the replacement in C++11
    array_ptr[ 9 ] = 99;
    std::cout << array_ptr[ 9 ] << '\n';
    delete [] array_ptr;

}
/* output:

global operator 'new' was called
10
global operator delete was called
global operator 'new' was called
99
global operator delete was called

*/
