/**
std::basic_filebuf
**/


/// 02_std::basic_filebuf::swap
/**
void swap ( std::basic_filebuf& rhs);

Swaps the state and the content of *this and rhs.
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
        std::cout<<s<<std::endl; /// output the first line of test.in
        fin.rdbuf()->swap(*fout.rdbuf()); /// swap the underlying buffers.

        std::getline(fin, s); /// fail: con not read form a write-only filebuf
        std::cout<<s <<std::endl; /// print empty line.
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

