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

    std::ifstream input_file_stream( "file_2" );    // how are you today?\nI am file.\n
    std::streambuf* stream_buffer = input_file_stream.rdbuf();

    std::cout << (char)stream_buffer->sgetc() << '\n';      // h    [ like n ]
    std::cout << (char)stream_buffer->sbumpc() << '\n';     // h    [ like n++ ]

    std::cout << (char)stream_buffer->sgetc() << '\n';      // o    [ like n ]
    std::cout << (char)stream_buffer->snextc() << '\n';     // w    [ line ++n ]

    input_file_stream.close();

}
/**

h
h
o
w

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
