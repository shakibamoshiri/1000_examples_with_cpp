/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::ignore
//  basic_istream& ignore( streamsize n = 1, int_type delimiter = traits_type::eof() )
//
//  Extracts and discards characters.


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <limits>



int main(){

    std::ifstream input_file_stream( "file" );
    // first line of the file:
    // If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The

    input_file_stream.ignore( std::numeric_limits< std::streamsize >::max(), ')' );
    // ignore:
    // If the get pointer (gptr)
    input_file_stream.ignore(); // and ' ' space

    std::string line;
    std::getline( input_file_stream, line );

    std::cout << line << '\n';

    input_file_stream.close();

}
/**

has a value and this is less than the end pointer (egptr): The

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


**/
