/**
std::basic_istream
**/


/// 13_std::basic_istream::gcount
/**

std::streamsize gcount () const;

Returns the number of character extracted by the last unformatted input operation
The following member function of basic_istream change the value of substance gcount () calls.
    - move constructor
    - swap()
    - get()
    - getline()
    - ignore()
    - read()
    - readsome()
    - operator>>(basic_streambuf*)
The following function set gcount() to zero.
    - constructor
    - putpack()
    - unget()
    - peek()

Return value : The number of character extracted by the last unformatted input function.

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        char c[20];
        std::basic_istringstream<char> stream("hello world");

        stream.read(c , sizeof c);
        std::cout<<"Character extracted : "<<stream.gcount() <<std::endl;
        std::cerr<<c<<std::endl;

        char* t("null");
        stream.read(t ,sizeof t);
        std::cout<<t<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













