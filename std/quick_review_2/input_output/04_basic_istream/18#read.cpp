/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::read
//  basic_istream&  read( char_type* s, streamsize n )
//
//  Reads a block of data; 'n' characters from the stream and stores them in the array pointed by 's'.

// The number of characters successfully read and stored by this function can be accessed by calling
// member gcount.
#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <cctype>   // std::isdigit



int main(){

    std::ifstream input_file_stream( "file" );

    input_file_stream.seekg( 0, std::ios_base::end );
    std::size_t size_of_file = input_file_stream.tellg();
    input_file_stream.seekg( 0, std::ios_base::beg );

    char* buffer_for_file = new char[ size_of_file ];

    std::cout << "reading ... " << size_of_file << " ... characters from the file.\n";
    input_file_stream.read( buffer_for_file, size_of_file );

    if( input_file_stream ) std::cout << "all characters read successfully.\n";
    else                    std::cout << "error: only " << input_file_stream.gcount() << "could be read";
    input_file_stream.close();

    std::cout << "\n\n the buffer_for_file: content:\n";
    std::cout << buffer_for_file  << '\n';

    delete [] buffer_for_file;
}
/**

reading ... 505 ... characters from the file.
all characters read successfully.


 the buffer_for_file: content:
If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function returns the number of characters directly available at the get pointer before the end
pointer (i.e., it returns (egptr()-gptr()) without calling any virtual member function).
• If the get pointer (gptr) is either null or has reached the end pointer (egptr): The function
calls the protected virtual member function showmanyc to obtain the number of characters
expected to be available after an underflow.


**/
