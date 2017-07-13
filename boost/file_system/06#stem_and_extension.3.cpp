
#include <boost/filesystem.hpp>

//#include <cstdio>
//#include <regex>
#include <iostream>

namespace fs = boost::filesystem;


int main( ){

    fs::path user_path( "./temp.cpp" );

    std::cout << user_path.stem().string() + user_path.extension().string() << '\n';


}
/* the output:
temp.cpp

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



*/
