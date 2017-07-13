/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::get
//  int_type get()
//  basic_istream& get ( char_type& c )
//
//  basic_istream& get ( char_type* s, streamsize n )
//  basic_istream& get ( char_type* s, streamsize n, char_type delim )
//
//  basic_istream& get ( streambuf& sb )
//  basic_istream& get ( streambuf& sb, char_type delim )
//
//  Gets characters

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    char filename[ 30 ]{};

    std::cout << "Please enter a name of a file: ";
    std::cin.get( filename, 30 );

    std::ifstream input_file_stream( filename );    // open a file

    char single_char;
    while( input_file_stream.get( single_char ) )
        std::cout << single_char;

    input_file_stream.close();

}
/**
Please enter a name of a file: file
If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function returns the number of characters directly available at the get pointer before the end
pointer (i.e., it returns (egptr()-gptr()) without calling any virtual member function).
• If the get pointer (gptr) is either null or has reached the end pointer (egptr): The function
calls the protected virtual member function showmanyc to obtain the number of characters
expected to be available after an underflow.


**/
