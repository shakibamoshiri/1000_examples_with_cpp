/**
std::basic_filebuf
**/


/// 01_std::basic_filebuf::operator=
/**
std::basic_fiebuf& operator= ( std::basic_filebuf&& rhs);
std::basic_fiebuf& operator= ( const std::basic_filebuf& rhs) = delete;

Assigns another basic_filebuf object.
1)  First calls close() to close the associated file, then moves the contents
    of rhs into *this: the put and get buffers, the associated file, the locale,
    the openmode, the is_open flag, and any other state. After the move, rhs is
    not associated with a file and rhs.is_open() == false.
2)  The copy associated operator is deleted; basic_filebuf is not CopyAssignable.

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
        std::ifstream fin("test.in"); /// read-only
        std::ofstream fout("test.out"); /// write-only

        std::string s;
        std::getline(fin, s);
        std::cout <<s <<std::endl; /// output

        *fin.rdbuf()  = std::move(*fout.rdbuf());
        std::cout.setf(std::ios_base::boolalpha);
        std::cout<<fout.is_open() << std::endl; /// print "false"
        /// or you can use it:
        std::cout<<std::boolalpha<<fout.is_open() << std::endl; /// print "false"
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

