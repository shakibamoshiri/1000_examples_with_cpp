
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "/home/shu/" );

    std::cout << user_path.root_name() << '\n'
              << user_path.root_directory() << '\n'
              << user_path.root_path() << '\n'
              << user_path.relative_path() << '\n'
              << user_path.parent_path() << '\n'
              << user_path.filename() << '\n';


}
/* the output:

""
"/"
"/"
"home/shu/"
"/home/shu"
"."

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

*/
