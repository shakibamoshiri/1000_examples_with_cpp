/**
std::basic_streambuf
**/


/// 03_std::basic_streambuf::pubsetbuf and setbuf
/**
1. basic_streambuf<charT, traits>* pubsetbuf(char_type* s, std::streamsize n);
2. virtual basic_streambuf<charT, traits>* setbuf(char_type* s, std::streamsize n);

1)  Calls setbuf(s,n) of the most derived class.
2)  The base class version of this function has no effect. The derived classed may
    override the function to allow removal or replacement of the controlled character
    sequence ( the buffer ) with a user-provided array, or for any other
    implementation-specific purpose.

**/


#include <iostream>
#include <fstream>
#include <string>



int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        int c = 0;
        std::ifstream ifs;
        char buf[10241];

        ifs.rdbuf()->pubsetbuf(buf, sizeof buf);
        ifs.open("/usr/share/dict/words");

        for( std::string line; std::getline(ifs, line);){
            c++;
            /// std::cout<<line<<std::endl; additional
        }
        std::cout<<" c : " <<c<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













