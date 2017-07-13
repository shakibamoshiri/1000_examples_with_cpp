
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./does_not_exist" );
    std::cout << user_path.string() << '\n';

    // but if we want to use it, it throw an exception
    uintmax_t size_of_file = -1;
    try{
        size_of_file = fs::file_size( user_path ); // it throws

    } catch( fs::filesystem_error fe ){
        std::fprintf( stderr, "%s:\n", fe.what() );
    }


}
/* the output:
./does_not_exist
boost::filesystem::file_size: No such file or directory: "./does_not_exist":

Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue


*/
