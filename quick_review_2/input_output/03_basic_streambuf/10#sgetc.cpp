/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sgetc
//  int_type sgetc();
//
//  Gets current character

// Notice that, although similar, the following member functions have different behaviors:
//
//  sgetc()     [ like n ]
//  returns the character at the current position.
//
//  sbumpc()    [ like n++ ]
//  returns the character at the current position and advances the current position to the next character.
//
//  snextc()    [ line ++n ]
//  advances the current position to the next character and returns this next character.


#include <iostream> // std::cout, std::ios
#include <fstream>
#include <unistd.h>



int main(){

    // show file content with sgetc()

    std::ifstream input_file_stream( "file_2" );    // how are you today?\nI am file.\n
    std::streambuf* stream_buffer = input_file_stream.rdbuf();

    do {
        char chr = stream_buffer->sgetc();
        std::cout << chr;
    }while( stream_buffer->snextc() != std::streambuf::traits_type::eof() );

    input_file_stream.close();

}
/**
how are you today?
I an fine.

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.


**/
