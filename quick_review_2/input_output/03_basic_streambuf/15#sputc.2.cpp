/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sputc
//  int_type sputc( char_type c );
//
//  Put character and advance to next position



#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>




int main(){

    // typewriter - sputc()
    std::ofstream output_file_stream( "file_3" );
    std::streambuf* stream_buffer = output_file_stream.rdbuf();

    std::cout << "writing to a file. Type a '.' to end\n";

    do{
        stream_buffer->sputc( std::cin.peek() );
    }while( std::cin.get() != '.' );

    output_file_stream.close();
}
/**
the same result as 14_basic_streambuf_sputc.cpp


**/
