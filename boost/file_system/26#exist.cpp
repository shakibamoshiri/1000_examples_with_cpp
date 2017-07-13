
#include <boost/filesystem.hpp>
//#include <cstdio>
#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <regex>
#include <sys/dir.h>


/*

dir1
file1
file2
file3
    dir2
    file1
    file2
        dir3
        file1

*/
namespace fs = boost::filesystem;

class Find {
private:
    const fs::path      input_path__;
    const std::string   input_pattern__;
    const std::regex    regex_pattern__;

public:
    void in_path( const fs::path& p ){
    }
    bool path_was_valid(){
        return fs::exists( input_path__ );
    }
    void with_pattern(){}

};

int main(  ){




}
/* the output:

*/
