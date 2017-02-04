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


struct S {
    int array [ 2 ][ 3 ] = {
        {21, 22, 23},
        {24, 25, 26}
    };
};
int main(){

    // array - r-value

    int array [ 2 ][ 3 ] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    function( std::move( array ) );                 // okay, binds to x-value

    function( { {11, 12, 13}, {14, 15, 16} } );     // okay, prints ....

    S s0;   // an instance of S
//    function( s0.array );                           // error: (compiler) cannot bind ‘int [2][3]’ lvalue to ‘int (&&)[2][3]’

    function( S().array );                          // okay, prints ....

}



/* output:


*/
