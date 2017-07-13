/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::getline
//  basic_istream& getline( char_type* s, streamsize n );
//  basic_istream& getline( char_type* s, streamsize n, char_type delimiter );
//
//  Get line
//  Unformated input and stores them into 's' as a C-string


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );
    std::string line_1;

    line_1.resize( 20 );
    char line_2[ 20 ];

    input_file_stream.getline( line_2,               20 , '(');
    input_file_stream.seekg( std::ios_base::beg );
    input_file_stream.getline( &( *line_1.begin() ), 20, '(' );


    std::cout << line_1 << '\n';
    std::cout << line_2 << '\n';

    input_file_stream.close();

}
/**
If the get pointer
If the get pointer

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.




**/
