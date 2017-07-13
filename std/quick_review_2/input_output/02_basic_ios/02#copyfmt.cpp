/*

A review of abstraction section from cplusplus.com

*/

/// basic_ios::copyfmt
//  basic_ios& copyfmt( const basic_ios& rhs )
//  Copy formating information







#include <iostream> // std::cout, std::ios
#include <fstream>

int main(){

    std::basic_ofstream< char > output_stream;
    output_stream.open( "file_1" );

    std::cout.fill( '#' );  // set '#'
    std::cout.width( 10 );  //

    output_stream.copyfmt( std::cout );

    std::cout << 20;        // ########20
    output_stream << 20;    // ########20

    output_stream.close();


}
/**

########20
Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


**/
