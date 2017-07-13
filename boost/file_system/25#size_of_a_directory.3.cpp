
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
    // third:
    try {
        const boost::uintmax_t size_of_file = fs::file_size( user_path );
        std::printf( "size of the file is: %d\n", size_of_file );
    } catch( const fs::filesystem_error& fe ){
        //std::fprintf( stderr, "%s\n", fe.what() );

        boost::uintmax_t size_of_file = -1;
        for( const fs::directory_entry& de : fs::directory_iterator( user_path ) ){
            size_of_file += fs::file_size( de );
        }
        std::printf( "size of the directory is: %d\n", size_of_file );
    }

}
/* the output:

size of the directory is: 18814
*/
