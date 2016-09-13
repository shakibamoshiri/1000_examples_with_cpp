/**
std::basic_ofstream
**/

/// 07_std::basic_ofstream::swap(std::basic_fstream)
/**
template<class CharT, class Traits>
void swap( basic_fstream<CharT, Traits>& lhs, basic_fstream<CharT, Traits>& rhs);

Specialize the std::swap algorithm for std::basic_fstream.
Exchanges the state of "lhs" with that of "rsh".
Effectively calls lhs.swap(rsh).


**/
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::fstream f1("example1", std::ios_base::out),
                    f2 ("example2", std::ios_base::out),
                    f3  ("example3", std::ios_base::out);
        std::boolalpha(std::cout);
        std::cout<<f1.is_open()<<std::endl
                 <<f2.is_open()<<std::endl
                 <<f3.is_open()<<std::endl;
        f1.close();
        f2.close();
        /// f3 does not close
        std::cout<<f1.is_open()<<std::endl
                 <<f2.is_open()<<std::endl
                 <<f3.is_open()<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

