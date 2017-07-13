/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::gcount
//  streamsize gcount() const;
//
//  Gets character count.
//
// The unformatted input operations that modify the value returned by this function are:
// get, getline, ignore, peek, read, readsome, putback and unget.
//
// Notice though, that peek, putback and unget do not actually extract any characters, and thus
// gcount will always return zero after calling any of them.


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );
    std::string one_word;   // size == 0 but capacity == 15 by default
    std::cout << one_word.capacity() << '\n';

    one_word.resize( 15 );

    input_file_stream.getline( &( *one_word.begin() ), 15 );
    std::cout << one_word << '\n';
    std::cout << one_word.size() << '\n';
    std::cout << one_word.capacity() << '\n';
    std::cout << input_file_stream.gcount() << '\n';
    input_file_stream.close();

}
/**



**/
