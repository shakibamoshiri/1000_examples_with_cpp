/**
std::basic_ifstream
**/

/// 00_std::basic_ifstream::basic_ifstream ( constructor )
/**
basic_ifstream();
explicit basic_ifstream ( const char* filename, ios_base::openmode = ios_base::in);
explicit basic_ifstream ( const string& filename, ios_base::openmode = ios_base::in);
basic_ifstream ( basic_ifstream&& other); sine c++11
basic_ifstream ( const basic_ifstream& other) = delete; sine c++11

Construct new file stream.
1)  Default constructor: constructs a stream that is not associated
    with a file: default-constructs the std::basic_filebuf and
    constructs the base with the pointer to this default-constructed
    std::basic_filebuf member
2)  First, performs the same steps as the default constructor, then
    associates the stream with a file by calling rdbuf()->open(filename, mode|std::ios_base::in)
    (see std::basic_filebuf::open for the details on the effects of the
     call ), if the open() call returns a null pointer, sets setstate(failbit).
3)  Same as basic_ifstream(filename.c_str(), mode).
4)  Move constructor. First, move-constructor the base class from other
    ( which does not affect the rdbuf() pointer ),then move-constructor
    the std::basic_filebuf member, then call this->set_rdbuf() to install
    the new basic_filebuf as the rdbuf() pointer in the base class.
5)  The copy-constructor is deleted: this class is not copyable.


**/
#include <iostream>
#include <utility>
#include <fstream>

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::ifstream f0;
        std::ifstream f1("test.bin", std::ios_base::binary);
        std::string name = "example.txt";
        std::ifstream f2(name);
        std::ifstream f3(std::move(f1));
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

