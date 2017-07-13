
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "/home/shu/" );

    std::cout << user_path.has_branch_path() << '\n'    // 1
              << user_path.has_extension() << '\n'      // 0
              << user_path.has_filename() << '\n'       // 1
              << user_path.has_leaf() << '\n'           // 1
              << user_path.has_parent_path() << '\n'    // 1
              << user_path.has_relative_path() << '\n'  // 1
              << user_path.has_root_directory() << '\n' // 1
              << user_path.has_root_name() << '\n'      // 0
              << user_path.has_root_path() << '\n';     // 1


}
/* the output:

1
0
1
1
1
1
1
0
1

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.

*/
