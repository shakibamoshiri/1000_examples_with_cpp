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
    output_stream.open( "file_2" );

    output_stream.fill( '#' );  // set '#'
    output_stream.width( 20 );
    output_stream << 20;        // ###################20

    output_stream.close();


}
/** inside the file_2
###################20



**/
