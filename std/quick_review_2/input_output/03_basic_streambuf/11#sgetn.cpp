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


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>




int main(){

    // read a file into buffer with sgetn()

    std::ifstream input_file_stream( "file_2" );    // how are you today?\nI am file.\n
    std::streambuf* stream_buffer = input_file_stream.rdbuf();
    char* whole_file = nullptr;

    std::streamsize size = stream_buffer->pubseekoff( 0, std::ios_base::end );
    stream_buffer->pubseekoff( 0, std::ios_base::beg ); // rewind

    whole_file = new char[ size ];
    stream_buffer->sgetn( whole_file, size );

    input_file_stream.close();  // close the file stream

    std::cout << whole_file << '\n';

    delete [] whole_file;

}
/**
how are you today?
I an fine.


Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



**/
