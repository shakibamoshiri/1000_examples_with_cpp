
#include <boost/filesystem.hpp>
//#include <cstdio>
#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>

namespace fs = boost::filesystem;



int main(  ){

    fs::path user_path( "01/" );

    // how to handle that?
    // first:
    if( fs::is_directory( user_path ) ){
        std::fprintf( stderr, "Error you file is a directory not a file" );
    } else {
        const boost::uintmax_t size_of_file = fs::file_size( user_path );
        std::printf( "size of the file is: %d\n", size_of_file );
    }

}
/* the output:

Error you file is a directory not a file
*/
