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
    std::string one_word;

    input_file_stream >> one_word;
    std::cout << one_word.size() << '\n';               // 2 == "If"
    std::cout << input_file_stream.gcount() << '\n';    // 0 since this is a FormatedOutput

    one_word.resize( 15 );  // == char one_word[ 15 ];
    input_file_stream.getline( &(*one_word.begin()), 15 );
    std::cout << one_word.size() << '\n';               // 15


    std::cout << input_file_stream.gcount() << '\n';    // 14

    input_file_stream.close();

}
/**

2
0
15
14

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


**/
