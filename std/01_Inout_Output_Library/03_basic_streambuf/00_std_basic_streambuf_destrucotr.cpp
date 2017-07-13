/**
std::basic_streambuf
**/


/// 00_std::basic_streambuf::~basic_streambuf
/**
virtual ~basic_streambuf

This destructor is empty: the member of this basic_streambuf ( the pointer
and the locale ) are destructor in accordance with the usual object destruction
sequence after this destructor returns. However, since it is declared pubic virtual,
it objects that are derived from std::basic_streambuf to be deleted through a pointer
to base class.
**/


#include <iostream>
#include <fstream>

std::ostream& operator<<(std::ostream& os, std::ifstream&& ifs){
    return os<<ifs.rdbuf();
}

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        std::basic_filebuf<char>* fbuf = new std::basic_filebuf<char>;
        fbuf->open("test_streambuf.txt", std::ios_base::out);
        fbuf->sputn("Hello\n",6);

        std::streambuf* sbuf(fbuf);
        delete fbuf;
        /// std::ifstream ifs("test_streambuf.txt");
        /// print use ifstream overloading
        std::cout<<std::ifstream("test_streambuf.txt")<<std::endl;
        /// std::cout<<ifs.rdbuf()<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













