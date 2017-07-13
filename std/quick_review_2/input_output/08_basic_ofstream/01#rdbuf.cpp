/*

A review of abstraction section from cplusplus.com

*/

/// basic_ofstream::rdbuf
//  basic_filebuf< char_type, traits_type >* rdbuf() const;
//
//  Gets stream buffer.
//
// Notice however, that this is not necessarily the same as the currently associated stream buffer
// (returned by basic_ios::rdbuf).


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <cstdio>   // EOF ( -1 )



int main(){

    std::ifstream input_file_stream( "file" );
    std::ofstream output_file_stream( "file_1" );

    std::filebuf* input_buffer  = input_file_stream.rdbuf();
    std::filebuf* output_buffer = output_file_stream.rdbuf();

    char chr = input_buffer->sbumpc();
    while( chr != EOF ){
        output_buffer->sputc( chr );        // writes into the file: file_1
        chr = input_buffer->sbumpc();       // read from the file
    }

    input_file_stream.close();
    output_file_stream.close();

}
/**



**/
