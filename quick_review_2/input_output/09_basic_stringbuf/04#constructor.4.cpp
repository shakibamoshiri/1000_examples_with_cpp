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

    std::stringbuf string_buffer( "How are you today?" );   // by default has ios_base::in and ios_base::out

    std::string word;
    word.resize( 3 );
    string_buffer.sgetn( &( *word.begin() ), 3 );
    std::cout << word << '\n';

}
/**
How

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



**/
