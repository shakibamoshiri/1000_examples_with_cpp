/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sputn
//  streamsize sputn( const char_type* s, streamsize n )
//
//  Puts sequence of characters.



#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>




int main(){

    // sputn9)

    const char some_text[] = "this is going to be sent to file_4";

    std::ofstream output_file_stream( "file_4" );
    std::streambuf* stream_buffer = output_file_stream.rdbuf();

    stream_buffer->sputn( some_text, sizeof( some_text ) - 1 ); // is sent to file_4

    output_file_stream.close();
}
/**



**/
