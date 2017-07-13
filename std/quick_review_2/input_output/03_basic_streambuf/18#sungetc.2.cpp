/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sungetc
//  int_type sungetc()
//
//  Decrease current position



#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>




int main(){

    // sungetc()
    std::istringstream iss( "abcdefg" );
    std::streambuf* stream_buffer = iss.rdbuf();

    std::cout << (char) stream_buffer->sgetc();  // extracts one character: a
    stream_buffer->sungetc();                    // equivalent to streambuf -> sungetc

    std::cout << (char) stream_buffer->sgetc();  // extracts one character: a
    stream_buffer->sungetc();                    // equivalent to streambuf -> sungetc

    std::cout << (char) stream_buffer->sgetc();  // extracts one character: a
    stream_buffer->sungetc();                    // equivalent to streambuf -> sungetc


}
/**

aaa

**/
