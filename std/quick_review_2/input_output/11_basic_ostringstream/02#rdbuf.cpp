/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostringstream rdbuf
//  basic_stringbuf<char_type,traits_type,allocator_type>* rdbuf() const;
//
//  Gets stream buffer

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>


int main(){

    std::ostringstream oss;
    // using stringbuf directly
    std::stringbuf* string_buf = oss.rdbuf();

    string_buf->sputn( "How are you today?", 18 );

    std::cout << string_buf->str() << '\n';

}
/**
How are you today?

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.



**/
