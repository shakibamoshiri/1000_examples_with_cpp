/**
std::basic_streambuf
**/


/// 20_std::basic_streambuf::pubsetbuf and setbuf
/**
basic_streambuf <charT, Traits>* pubsetbuf(char_type* s, std::streamsize n);
protected :
virtual basic_streambuf <charT, Traits>* pubsetbuf(char_type* s, std::streamsize n);

1)  Calls setbuf(s, n) of the most derived class.
2)  The base class version of the function has no effect. The derived classed may override
    this function to allow removal or replacement of the controlled character sequence (the
    buffer ) with a user-provided array, or for any other implementation-specific purpose.

**/
#include <iostream>
#include <sstream>
#include <fstream>
int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        int n=0;
        std::ifstream ifs;
        char buffer[11000];
        ifs.rdbuf()->pubsetbuf(buffer, sizeof buffer);
        ifs.open("/usr/share/dict/words");
        for(std::string line; std::getline(ifs, line);)
            n++;
        std::cout<<n<<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













