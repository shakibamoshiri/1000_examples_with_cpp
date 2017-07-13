/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostream::tellp
//  pos_type tellp()
//
//  Gets position in output sequence.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <string>


int main(){

    using namespace std::literals;
    std::ofstream output_file_stream;
    output_file_stream.open( "file_3" );

    output_file_stream.write( "how are you today?", "how are you today?"s.size() );
    long pos = output_file_stream.tellp();
    output_file_stream.seekp( pos - "you today?"s.size() );

    output_file_stream.write( "they today?", "they today?"s.size() );

    output_file_stream.close();
}
/**

**/
