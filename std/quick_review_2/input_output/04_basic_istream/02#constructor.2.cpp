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

    std::filebuf file_buffer_stream;
    file_buffer_stream.open( "file", std::ios_base::in );
//    std::streambuf* stream_buffer = input_file_stream.rdbuf();

    std::istream input_stream( &file_buffer_stream );

    std::string string;
    input_stream >> string;
    std::cout << string;    // If ( the first word in the file

    file_buffer_stream.close();
}
/**



**/
