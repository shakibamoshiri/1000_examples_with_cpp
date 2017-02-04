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



int main(){

    // array - r-value

    using arr2_t = int [ 2 ][ 3 ];

    arr2_t array = {
        {1, 3, 5},
        {0, 2, 4}
    };

//    function( array );      // error

    function( arr2_t{} );   // okay 0 0 0 0 0 0

}



/* output:


*/
