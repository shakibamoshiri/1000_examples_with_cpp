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
    std::istream input_stream ( &string_buffer );

    output_stream << "test output-stream";

    std::string string;
    string.resize( 18 );
    input_stream.getline( &( *string.begin() ), 18 );

    std::cout << string;

}
/**
test output-stream
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
