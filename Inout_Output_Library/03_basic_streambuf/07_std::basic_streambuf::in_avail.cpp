/**
std::basic_streambuf
**/


/// 07_std::basic_streambuf::in_avail
/**
std::streamsize in_avail

    Returns the number of character in the get area. If a read position is available,
effectively returns egptr() - gptr(), the size of the get area. In this case, the
number of bytes returned is the number of byte that can be extracted from the buffer
without calling underflow().
    If the get area is empty, calls showmanyc() to determine the number of bytes available
    in the associated character sequence. In this case, the value returned is the number of
    bytes that can be extracted form the buffer while it is guaranteed that underflow() would
    not return Traits::eof.
**/


#include <iostream>
#include <fstream>
#include <string>



int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        /// No sample
    }

    {
        /// msdn.microsoft.com
    }

}













