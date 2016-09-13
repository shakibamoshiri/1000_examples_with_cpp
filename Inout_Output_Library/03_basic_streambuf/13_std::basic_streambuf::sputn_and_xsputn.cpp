/**
std::basic_streambuf
**/


/// 13_std::basic_streambuf::sputn and xsputn
/**
std::streamsize sputn ( const char_type* s, std::streamsize count );
protected :
    virtual std::streamsize sputn ( const char_type* s, std::streamsize count );
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
        std::basic_ostringstream<char> s1;
        std::streamsize sz = s1.rdbuf()->sputn("This is a test of sputn",80);
        s1<<std::endl;
        std::cout<<"The call to sputn() returned : "<<sz<<std::endl;

        std::istringstream s2;
        sz = s2.rdbuf()->sputn("This is test of sputn",80);
        std::cout<<"The call to spunt() on an input stream returned : "<<sz<<std::endl;

    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













