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

    puts( "Enter a string with delimiter '.' please: " );
    char c_string[ 20 ]{};
    std::cin.get( c_string, 20, '.' );
    puts( c_string );

}
/**

Enter a string with delimiter '.' please:
abcd.efgh
abcd

Process returned 0 (0x0)   execution time : 10.517 s
Press ENTER to continue.


**/
