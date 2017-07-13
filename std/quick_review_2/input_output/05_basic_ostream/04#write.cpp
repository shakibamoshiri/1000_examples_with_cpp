/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostream::write
//  basic_ostraem& write( const char_type* s, streamsize n );
//
//  Write block of data.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <string>


int main(){

    std::ifstream input_file_stream( "file" );
    std::ofstream output_file_stream( "file_4" );

    input_file_stream.seekg( 0, std::ios_base::end );       // goes to end
    std::size_t size_of_file = input_file_stream.tellg();   // gets the size
    input_file_stream.seekg( 0, std::ios_base::beg );       // rewind

    char* buffer_for_file = new char[ size_of_file ];

    input_file_stream.read( buffer_for_file, size_of_file );    // extracts from the file into the buffer
    input_file_stream.close();

    output_file_stream.write( buffer_for_file, size_of_file );  // extracts from the buffer into the new file: file_4
    output_file_stream.close();

    delete [] buffer_for_file;
}
/**

**/
