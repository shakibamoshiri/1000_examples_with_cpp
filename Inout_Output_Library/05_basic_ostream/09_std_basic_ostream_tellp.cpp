/**
std::basic_ostrream
**/


/// 09_std::basic_ostream::tellp
/**
pos_type tellp();

Return the output position indicator of the current associated streambuf object.
If fail() = true, return pos_type(-1). Otherwise, return rdbuf()->pubesskoff(0
                                                         , std::ios_base::cur, std::ios_base::out).
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
        std::basic_ostringstream<char> s;
        std::cout<< s.tellp() << std::endl;
        s << 'h';
        std::cout<< s.tellp() << std::endl;
        s << "ello, world ";
        std::cout<< s.tellp() << std::endl;
        s << 45 << std::endl;
        std::cout<< s.tellp() << std::endl << s.str() << std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













