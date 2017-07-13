/*

A review of abstraction section from cplusplus.com

*/

/// basic_stringbuf constructor
//  a stream buffer to read from or write to basic_string object.

//  explicit basic_stringbuf ( ios_base::opnemode which = ios_base::in | ios_base::out );
//  explicit basic_stringbuf ( const basic_string<char_type,traits_type,allocator_type>& str, ios_base::opnemode which = ios_base::in | ios_base::out );
//  explicit basic_stringbuf ( const basic_stringbuf& ) delete; // copy
//  explicit basic_stringbuf ( const basic_stringbuf&& x );     // move

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>



int main(){

    std::stringbuf string_buffer;

    string_buffer.sputn( "this is going to go into the string_buffer", 39 );    // like string_buffer << " ... "

    char some_buffer[ 39 ];
    string_buffer.sgetn( some_buffer, 39 );                                     // like string_buffer.getline( ..., ... )

    std::cout << some_buffer << '\n';

}
/**

this is going to go into the string_buf

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



**/
