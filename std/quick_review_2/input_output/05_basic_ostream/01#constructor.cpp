/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostream::basic_ostream ( constructor )
//  explicit basic_ostream (basic_streambuf<char_type,traits_type>* sb);
//  explicit basic_ostream ( const basic_ostream& ) = delete;
//  protected:
//  explicit basic_ostream ( basic_ostream&& rhs);
//
//  Constructs objects.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>


int main(){

    std::filebuf file_buffer;
    file_buffer.open( "file_1", std::ios_base::out );

    std::ostream output_stream( &file_buffer ); // explicit basic_ostream (basic_streambuf<char_type,traits_type>* sb);

    output_stream << "this a test on std::ostream constructor...\n";
    file_buffer.close();
}
/**

**/
