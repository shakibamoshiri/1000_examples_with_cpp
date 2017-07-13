/*

A review of abstraction section from cplusplus.com

*/

/// basic_filebuf::basic_filebuf   constructor
//

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::filebuf input_file_buffer_stream;
    std::filebuf output_file_buffer_stream;

    input_file_buffer_stream.open( "file", std::ios_base::in );     // read-only because of using ::in
    output_file_buffer_stream.open( "file_1", std::ios_base::out ); // write-only

    char* allocated_buffer = new char[ 100 ];

    input_file_buffer_stream.sgetn( allocated_buffer, 100 );    // read from the file into the buffer
    input_file_buffer_stream.close();

    output_file_buffer_stream.sputn( allocated_buffer, 100 );   // write from the buffer into the file
    output_file_buffer_stream.close();

    delete [] allocated_buffer;
}
/**

**/
