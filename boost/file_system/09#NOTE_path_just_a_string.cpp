
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./does_not_exist" );
    std::cout << user_path.string() << '\n';


}
/* the output:

./does_not_exist

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.


*/
