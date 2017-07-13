/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostream::seekp
//  basic_ostream& seekp( pos_type pos );
//  basic_ostream& seekp( pos_type pos, ios_base::seekdir way );
//
//  Sets position in output sequence.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <string>


int main(){

    using namespace std::literals;
    std::ofstream output_file_stream;
    output_file_stream.open( "file_2" );

    output_file_stream.write( "how are you today?", "how are you today?"s.size() );
    long pos = output_file_stream.tellp();
    output_file_stream.seekp( pos - "you today?"s.size() );

    output_file_stream.write( "they today?", "they today?"s.size() );

    output_file_stream.close();
}
/**

**/
