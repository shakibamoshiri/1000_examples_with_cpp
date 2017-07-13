/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>
#include <string>


// #include <iomanip>



void function( int ( &&rmove )[ 2 ][ 3 ] ){
    std::cout << rmove[ 0 ][ 0 ] << ' '
              << rmove[ 0 ][ 1 ] << ' '
              << rmove[ 0 ][ 2 ] << ' '
              << rmove[ 1 ][ 0 ] << ' '
              << rmove[ 1 ][ 1 ] << ' '
              << rmove[ 1 ][ 2 ] << ' '
              << std::endl;             // 1 2 3 4 5 6
}

template< typename T > using identity = T;

int main(){

    // array - r-value
    using arr_2_t = int [ 2 ][ 3 ];

    function( identity< arr_2_t >{ {1,2,3}, {4,5,6} } );                // okay

    function( identity< int[ 2 ][ 3 ] >{ {11,12,13}, {14,15,16} } );    // okay
    function( identity< int[ ][ 3 ] >{ {11,12,13}, {14,15,16} } );      // also okay

}



/* output:


*/
