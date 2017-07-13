/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::pubseekpos
//  pos_type pubseekpos( pos_type pos, ios_base::openmode which = ios_base::in | ios_base::out )
//
//  Sets internal position pointer to absolute position

#include <iostream> // std::cout, std::ios
#include <fstream>


// This example reads and prints 10 characters of a file starting at position 10 (characters 11th to 20th)
int main(){

    // change position with pubseekpos

    std::ifstream input_file_stream( "file" );

//    std::streambuf* sb = input_file_stream.rdbuf();
    long size = input_file_stream.rdbuf()->pubseekoff( 0, std::ios_base::end );

    if( size > 20 ){
        char buffer[ 11 ];
        input_file_stream.rdbuf()->pubseekpos( 10 );       // change the position to 10th character
        input_file_stream.rdbuf()->sgetn( buffer, 10 );    // read the 10 characters
        buffer[ 10 ] = 0;           // append null character to string
        std::cout << buffer << '\n';
    }

    input_file_stream.close();

}
/**

 pointer (

Process returned 0 (0x0)   execution time : 0.009 s
Press ENTER to continue.

**/
