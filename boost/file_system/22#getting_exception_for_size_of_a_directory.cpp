
#include <boost/filesystem.hpp>
//#include <cstdio>
#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>

namespace fs = boost::filesystem;



int main( ){

    fs::path user_path( "01/" );

    boost::uintmax_t size_of_file = fs::file_size( user_path ); //throw an exception

}
/* the output:

terminate called after throwing an instance of 'boost::filesystem::filesystem_error'
  what():  boost::filesystem::file_size: Operation not permitted: "01/"
Aborted (core dumped)
*/
