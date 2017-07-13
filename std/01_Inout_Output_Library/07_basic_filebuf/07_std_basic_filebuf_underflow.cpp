/**
std::basic_filebuf
**/

/// protected  member :
/// 07_std::basic_filebuf::underflow
/**

protected:
virtual int_type underflow();
Reads more date into the input area.

Behaves like the base class std::basic::streambuf::underflow, except that to
read the date from the associated character sequence( the file) into the get
area, first reads the bytes from the file into a temporary buffer( allocated as large as necessary ),
then uses std::codecvt::in or the imbued locale to convert the external (typically, multibyte)
representation to the internal form which is then used to populate the get area.
The conversion may be skipping if the locale's std::codecvt::always_noconv returns true.

**/
#include <iostream>
#include <sstream>
#include <fstream>
struct user_buf : std::filebuf
{
    int underflow() {
         std::cout << "Before underflow(): size of the get area is "
                   << egptr()-eback() << " with "
                   << egptr()-gptr() << " read positions available\n";
         int rc = std::filebuf::underflow();
         std::cout << "underflow() returns " << rc << ".\nAfter the call, "
                   << "size of the get area is "
                   << egptr()-eback() << " with "
                   << egptr()-gptr() << " read positions available\n";
        return rc;
    }
};

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
    user_buf buf;
    buf.open("test.txt", std::ios_base::in);
    std::istream stream(&buf);
    while(stream.get()) ;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

