/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::basic_istream
//  explicit basic_istream( streambuf* sb );
//  protected:
//  basic_istream( const basic_istream& ) = delete;
//  basic_istream&( basic_istream&& is );
//
// Constructs on object


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>


int main(){

    std::ifstream input_file_stream( "file" );
//    std::streambuf* stream_buffer = input_file_stream.rdbuf();

    std::istream input_stream( input_file_stream.rdbuf() ); // explicit basic_istream( streambuf* sb )

    std::string string;
    input_stream >> string;
    std::cout << string;    // If ( the first word in the file

}
/**



**/
