/**
std::basic_fstream
**/

/// 06_std::basic_fstream::close
/**

void close();
Effectively calls rdbuf()->closer(). If an error occurs during operation,
setstate(failbif) is called.

NOTE: This function is called by the destructor of basic_fstream
when the stream object goes out of scope and is not usually invoked directly.

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
        std::fstream f1("example.1", std::ios_base::out),
                     f2("example.2", std::ios_base::out),
                     f3("example.3", std::ios_base::out);
        std::boolalpha(std::cout);
        std::cout<<f1.is_open()<<std::endl
                 <<f2.is_open()<<std::endl
                 <<f3.is_open()<<std::endl;
        f1.close();
        f3.close();
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

