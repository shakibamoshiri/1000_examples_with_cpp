/**
std::basic_filebuf
**/

/// protected  member :
/// 08_std::basic_filebuf::uflow
/**

protected:
Behaves like the underflow(), except that if underflow() succeeds
( does not return Traits::eof()), then advances the next pointer for
the get area. In other words, consumes one of the character obtained by underflow().

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

