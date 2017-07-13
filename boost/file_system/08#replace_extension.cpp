
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./one.txt" );

    user_path.replace_extension( "pdf" );

    std::cout << user_path.string() << '\n';


}
/* the output:

./one.pdf

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


*/
