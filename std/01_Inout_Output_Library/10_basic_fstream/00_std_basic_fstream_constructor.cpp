/**
std::basic_fstream
**/

/// 00_std::basic_fstream
/**
1.  basic_fstream();
2.  explicit basic_fstream(const char* filename);
3.  explicit basic_fstream(const string& filename);
4.  basic_fstream( basic_fstream&& other); since c++11
5.  basic_fstream(const basic_fstream& rhs) = delete; since c++11

All of them constructs new file stream but with a little difference.

1)  Default constructor: constructs a stream that is not associated
    with a file: default-constructs the std::basic_filebuf and constructs
    the base with the pointer to this default-constructed std::basic_filebuf
    member.
2)  First, performs the same steps as the default constructor, then associates
    the stream with a file by calling rdbuf()->open(filename, mode)(see std::
    basic_filebuf::open for the default on the effects of the call). if the
    open() call returns a null pointer, sets setstate(failbif).
3)  Same as basic_filebuf(filename.c_str, mode).
4)  Move constructor. First, move-constructs the base class from other
    (which does not affect the rdbuf() pointer) /// Affect: AW : your opinion will not affect my decision.
    then move-constructs the std::basic_filebuf member, the call this->set_rdubf()
    to install the new basic_filebuf as the rdbuf() pointer in the base class
5)  The copy-constructor is deleted this class is not copyable.


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
        std::fstream f0;
        std::fstream f1("test.bin", std::ios_base::binary);
        std::string name("example.txt");
        std::fstream f2(name);
        std::fstream f3(std::move(f1));
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

