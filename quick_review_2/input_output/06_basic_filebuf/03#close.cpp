/*

A review of abstraction section from cplusplus.com

*/

/// basic_filebuf::close
//  basic_filebuf* close();
//
//  Closes file.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );
    std::filebuf* fb_ptr = input_file_stream.rdbuf();
    fb_ptr->open( "file", std::ios_base::in );

    char static_buffer[ 20 ];
    fb_ptr->sgetn( static_buffer, 20 );
    std::cout << static_buffer << '\n';

    fb_ptr->close();

}
/**
If the get pointer (

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.
**/
