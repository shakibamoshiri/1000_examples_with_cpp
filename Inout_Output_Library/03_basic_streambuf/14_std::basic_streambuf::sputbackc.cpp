/**
std::basic_streambuf
**/


/// 14_std::basic_streambuf::sputbackc
/**
int_type sputbackc ( char_type c);

Put back a character back to the get area.
If a putback position is available in the get area ( gptr()->eback()), and the
character 'c' is equal to the character one position to the left of gptr() (as
determinded by Traits::eq(c, gptr()[-1]), then simply decrements the next pointer (pgtr()).
Otherwise, calls pbackfail(Traits::to_int_type(c)) to either back up the get area or to
modify both the get area and possible the associated character sequence.
The I/O stream function basic_istream::putback is implemented in terms of this function.


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
        std::cout<<"Before putback, string holds : "<<s.str() <<std::endl;
        char c1 = s.get(); /// c1 = 'a', gptr() new points to 'b' "abcdef"
        char c2 = s.rdbuf()->sputbackc('z'); /// same as s.putback('z')
            /// gptr() now points to 'z' in "zabcde"
        std::cout<<"After putback, string holds : "<<s.str()<<std::endl;

        char c3 = s.get(); /// c3 = 'z', gptr() now points to 'b' in "zbcdef"
        char c4 = s.get(); /// c4 = 'b', gptr() new points to 'c' in "zbcdef"
        std::cout<<c1 <<c2 <<c3 <<c4 <<std::endl;

        s.rdbuf()->sputbackc('b'); /// pgtr() now points to 'b' in "zbcdef"
        s.rdbuf()->sputbackc('z'); /// gptr() new points to 'z' in "zabcde"

        int eof = s.rdbuf()->sputbackc('x'); /// nothing to unget : pbackfail() fails
        if(eof == EOF)
            std::cout<<"No room to putback after'z'\n";
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













