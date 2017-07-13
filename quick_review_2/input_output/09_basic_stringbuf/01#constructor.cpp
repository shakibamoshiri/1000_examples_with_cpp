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
    std::ostream output_stream( &string_buffer );   // associate stream buffer to stream

    // mixing output to buffer with inserting to associated stream:
    string_buffer.sputn( "255 in hexadecimal: ", 20 );
    output_stream << std::hex << 255;

    std::cout << string_buffer.str() << '\n';

}
/**

255 in hexadecimal: ff

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.


**/
