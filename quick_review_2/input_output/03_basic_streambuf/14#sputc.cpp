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
    char chr;

    std::cout << "writing to a file. Type a '.' to end\n";

    do{
        chr = std::cin.get();   // return one character
        stream_buffer->sputc( chr );
    }while( chr != '.' );

    output_file_stream.close();
}
/**
writing to a file. Type a '.' to end
How are you tdaoy? I am fine. but ....

Process returned 0 (0x0)   execution time : 24.573 s
Press ENTER to continue.

---------------
cat file_3:
How are you tdaoy? I am fine.
**/
