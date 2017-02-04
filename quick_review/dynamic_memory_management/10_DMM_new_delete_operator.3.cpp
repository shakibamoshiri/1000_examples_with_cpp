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


//void* operator new( std::size_t size ){
//    std::cout << "global operator 'new' was called for single\n";
//    return std::malloc( size );
//
//}
//void operator delete( void* ptr ){
//    std::cout << "global operator delete was called for single\n";
//    std::free( ptr );
//}



void* operator new[]( std::size_t size, char character ){
    std::cout << "global operator 'new' was called for 'char'\n";
    return std::malloc( size );
}
void* operator new[]( std::size_t size, int integer ){
    std::cout << "global operator 'new' was called for 'int'\n";
    return std::malloc( size );
}

void operator delete[]( void* ptr ){
    std::cout << "global operator delete was called for array\n";
    std::free( ptr );
}


int main(){

    char* chr = new( 'c' ) char[ 4 ];
    chr [ 3 ] = 'A';
    std::cout << chr[ 3 ] << '\n';
    delete [] chr;

    int* itr = new( 1 ) int[ 4 ];
    itr[ 3 ] = 33;
    std::cout << itr[ 3 ] << '\n';
    delete [] itr;

}
/* output:

global operator 'new' was called for 'char'
A
global operator delete was called for array
global operator 'new' was called for 'int'
33
global operator delete was called for array

*/
