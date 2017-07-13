/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::ignore
//  basic_istream& ignore( streamsize n = 1, int_type delimiter = traits_type::eof() )
//
//  Extracts and discards characters.


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::ifstream input_file_stream( "file" );
    // first line of the file:
    // If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The

    input_file_stream.ignore(); // ignore I
    input_file_stream.ignore(); // ignore F
    input_file_stream.ignore(); // ignore ' ' space

    std::string word;
    input_file_stream >> word;
    std::cout << word << '\n';

    input_file_stream.close();

}
/**
the

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
