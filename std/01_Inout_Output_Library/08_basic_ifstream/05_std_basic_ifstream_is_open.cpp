/**
std::basic_ifstream
**/

/// 05_std::basic_ifstream::is_open
/**

bool is_open();
bool is_open() const;

Checks if the file stream has an associated file.
Effectively calls rdbuf()->is_open().
**/
#include <iostream>
#include <string>
#include <fstream>
/// this file is called main.cpp
bool file_exists( const std::string& str){
    std::ifstream fs(str);
    return fs.is_open();
}
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::boolalpha(std::cout);
        std::cout<<file_exists("TEMPFREE.cpp") << std::endl /// okay tempfree.cpp is exist
                 <<file_exists("strange_file")<<std::endl; /// strange_file does not exist
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

