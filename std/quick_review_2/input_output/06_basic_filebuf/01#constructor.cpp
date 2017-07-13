/*

A review of abstraction section from cplusplus.com

*/

/// basic_filebuf::basic_filebuf   constructor
//

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>



int main(){

    std::filebuf file_buf;
    file_buf.open( "file", std::ios_base::in ); // read-only because of using ::in

    char buffer_for_file[ 100 ];
    file_buf.sgetn( buffer_for_file, 100 );
    std::cout << buffer_for_file << '\n';

    file_buf.close();

}
/**

If the get pointer (gptr) has a value and this is less than the end pointer (egptr): The
function re

**/
