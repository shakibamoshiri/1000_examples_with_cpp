
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./temp.cpp" );

    boost::system::error_code ec;
    const boost::uintmax_t sz = fs::file_size( user_path, ec );

    if( ec ) // false
        std::cout << ec << '\n';    // an appropriate error
    else    // true
        std::cout << sz << '\n';    // size of file
}
/* the output:



*/
