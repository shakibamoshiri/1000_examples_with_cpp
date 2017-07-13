/*

A review of abstraction section from cplusplus.com

*/

/// basic_istringstream rdbuf
//  basic_stringbuf<char_type,traits_type,allocator_type>* rdbuf() const;
//
//  Gets stream buffer.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>


int main(){

    std::istringstream iss;
    std::stringbuf* strbuf_ptr = iss.rdbuf();

    strbuf_ptr->str( "some examples" );
    int size = strbuf_ptr->in_avail();

    while( strbuf_ptr->in_avail() > 0 )
        std::cout << static_cast< char >( strbuf_ptr->sbumpc() );
}
/**



**/
