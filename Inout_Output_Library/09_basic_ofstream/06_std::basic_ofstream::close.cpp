/**
std::basic_ofstream
**/

/// 06_std::basic_ofstream::close
/**
void close();

Close the associated file.
Effectively calls rdbuf()->close(). if an error occurs during operation, setstate(failbif) is called.


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

