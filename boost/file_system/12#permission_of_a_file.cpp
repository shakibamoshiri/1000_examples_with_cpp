
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./temp.cpp" );

    fs::file_status fst( fs::status( user_path ) );

    const int  p = fst.permissions();   // in type of int

    std::printf( "%d", p );
}
/* the output:
436
Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



*/
