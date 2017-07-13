/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::readsone
//  streamsize readsome( char_type* s, streamsize n )
//
//  Reads data available in buffer


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <cctype>   // std::isdigit



int main(){

    std::ifstream input_file_stream( "file" );
    std::string line;
    line.resize( 20 );

    input_file_stream.read( &( *line.begin() ), 20 );
    std::cout << line << '\n';

    input_file_stream.seekg( std::ios_base::beg );  // rewind

    input_file_stream.readsome( &( *line.begin() ), 20 );
    std::cout << line << '\n';


    input_file_stream.close();
}
/**

If the get pointer (
If the get pointer (

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


**/
