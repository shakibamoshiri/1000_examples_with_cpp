
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./temp.cpp" );
    std::cout << user_path.string() << '\n';

    // but if we want to use it, it throw an exception
    uintmax_t size_of_file = -1;
    try{
        size_of_file = fs::file_size( user_path ); // it throws

    } catch( fs::filesystem_error fe ){
        std::fprintf( stderr, "%s:\n", fe.what() );
    }

    std::fprintf( stdout, "size of file is: %d\n", size_of_file );
}
/* the output:

./temp.cpp
size of file is: 581

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



*/
