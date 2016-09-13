/**
std::basic_ostrream
**/


/// 10_std::basic_ostream::seekp
/**
basic_ostream& seekp( pos_type pos );
basic_ostream& seekp( off_type off, std::ios_base::seekdir dir );
                                                   seekdir = seek direction beg , end , cur of stream

Sets the output position indicator of the current associated streambuf object.
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
        std::basic_ostringstream<char> s("hello world 45");
        std::cout<<s.str()<<std::endl;
        s.seekp(6);
        s << 'W';
        s.seekp(0,std::ios_base::end );
        s << '+';
        s.seekp(0);
        s << 'H';
        std::cout<<s.str()<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













