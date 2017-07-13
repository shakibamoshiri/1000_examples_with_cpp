
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "/home/shu/" );

    // iterate over a path
    for( const fs::path& p : user_path ){
        std::cout << p << '\n';
    }


}
/* the output:

"/"
"home"
"shu"
"."

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

*/
