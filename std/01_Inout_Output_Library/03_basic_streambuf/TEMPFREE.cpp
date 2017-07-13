/**
std::basic_streambuf
**/


/// 15_std::basic_streambuf::sungetc
/**

int_type sungetc();

IF a putback position is available in the get area ( gptr()->eback()),
then decrement the next pointer (gptr()) and returns the character it
now points to.
If a putback position is not available, then calls pbackfail() to back
up the input sequence if possible.
The I/O stream function basic_istream::unget in implemented in term of the function.

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
        std::basic_stringstream<char> s("abcdef"); /// gptr() point to 'a' in "abcdef"
        char c1 = s.get(); /// c = 'a', pgtr() now points to 'b'
        char c2 = s.rdbuf()->sungetc(); /// same as s.unget(): gptr() points to 'a' again
        char c3 = s.get(); /// c3 = 'a', gptr() now points to 'b'
        char c4 = s.get(); /// c4 = 'b', gptr() now points to 'c'
        std::cout<<c1 <<c2 <<c3 <<c4 <<std::endl;

        s.rdbuf()->sungetc(); /// back to 'b'
        s.rdbuf()->sungetc(); /// back to 'a'
        int eof = s.rdbuf()->sungetc(); /// nothing to unget: pbackfail() fails
        if(eof == EOF )
            std::cout<<"Nothing to unget() after 'a'\n";
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













