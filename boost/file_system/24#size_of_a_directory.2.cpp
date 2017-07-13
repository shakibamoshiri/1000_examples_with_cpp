
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
    // second:
    try {
        const boost::uintmax_t size_of_file = fs::file_size( user_path );
        std::printf( "size of the file is: %d\n", size_of_file );
    } catch( const fs::filesystem_error& fe ){
        std::fprintf( stderr, "%s\n", fe.what() );
    }

}
/* the output:
boost::filesystem::file_size: Operation not permitted: "01/"

*/
