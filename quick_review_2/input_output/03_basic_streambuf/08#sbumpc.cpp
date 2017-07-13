/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sbumpc
//  int_type sbumpc();
//
//  Gets current character and advance to next position

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

    // show file content with sbumpc()

    std::ifstream input_file_stream( "file" );
    if( input_file_stream ){
        std::streambuf* stream_buffer = input_file_stream.rdbuf();

        while( stream_buffer->sgetc() != std::streambuf::traits_type::eof() ){
            std::cout << (char)stream_buffer->sbumpc();
        }

        input_file_stream.close();
    }

}
/**
If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function returns the number of characters directly available at the get pointer before the end
pointer (i.e., it returns (egptr()-gptr()) without calling any virtual member function).
• If the get pointer (gptr) is either null or has reached the end pointer (egptr): The function
calls the protected virtual member function showmanyc to obtain the number of characters
expected to be available after an underflow.


**/
