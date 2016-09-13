/**
std::basic_ofstream
**/

/// 00_std::basic_ofstream
/**

basic_ofstream();
explicit basic_ofstream ( const char* filename, ios_base::openmode mode = ios_base::out );
explicit basic_ofstream ( const std::string& filename, ios_base::openmode mode = ios_base::out );
explicit basic_ofstream( basic_ofstream&& other );
explicit basic_ofstream( basic_ofstream&& other ) = delete;

1)  Default constructor: constructs a stream that is not associated with
     a file: default-constructs the std::basic_filebuf and constructs the
     base with the pointer to this default-constructed std::basic_filebef
     member.
2)  First, performs the same steps as the default constructor,then associates
    the stream with a file by calling rdbuf()->open(filename, mode | ios_base::out)
    (see std::basic_filebuf::open for the details on the effects of that call).
    if the  open() call returns a null pointer, sets setstate(failbit).
3)  Same as basic_ofstream ( filename.c_str() , mode).
4)  Move constructor. First, move-constructs the base class from "other"
    (which does not affect the rdbuf() pointer ), then move-constructs the
    std::basic_filebuf member, then call this->set_rdbuf() to install
    the new basic_filebuf as the rdbuf() pointer the base class.
5)  The copy-constructor is deleted: this class is not copyable.

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
        std::basic_ofstream<char> f0;
        std::basic_ofstream<char> f1("test.bin", std::ios_base::binary);
        std::basic_string<char> name("example.txt");
        std::basic_ofstream<char> f2(name);
        std::basic_ofstream<char> f3(std::move(f1));
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

