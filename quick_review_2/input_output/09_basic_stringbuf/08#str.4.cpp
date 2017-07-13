/*

A review of abstraction section from cplusplus.com

*/

/// basic_stringbuf::str
//  basic_string< char_type, traits_type, allocator_type > str() const;         // getter
//  void str( basic_string< char_type, traits_type, allocator_type >& str );    // setter
//
//  Gets and sets the content of the stream.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>



int main(){


    std::stringbuf string_buffer( "how are you today?" , std::ios_base::out | std::ios_base::ate );
    string_buffer.sputc( '\n' );
    string_buffer.sputn( "I am fine. How about you?", 24 );
    std::cout << string_buffer.str() << '\n';


}
/**

how are you today?
I am fine. How about you

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.


**/
