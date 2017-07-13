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
//  C memory management library



#include <iostream>
#include <cstdlib>



int main(){

    int* ptr = ( int* ) std::malloc( 5 * sizeof( int ) );   // allocates from memory for an array of 5 int(s)

    if( ptr ){  // checks against the null

        // initialize:
        for( int index = 0; index < 5; ++index ){ ptr[ index ] = index * index ; }

        // print:
        for( int index = 0; index < 5; ++index ){ std::cout << ptr[ index ] << ' '; }
    }

    std::free( ptr );


}
/* output:

0 1 4 9 16

*/
