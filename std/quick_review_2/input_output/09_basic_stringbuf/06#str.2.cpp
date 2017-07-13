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

    std::stringbuf string_buffer( "How are you today?" );   // by default has ios_base::in and ios_base::out
    string_buffer.str( "I am fine. How about you?" );
    std::cout << string_buffer.str() << '\n';

}
/**

I am fine. How about you?

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
