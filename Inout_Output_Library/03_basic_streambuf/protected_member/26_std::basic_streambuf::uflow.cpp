/**
std::basic_streambuf
**/


/// 26_std::basic_streambuf::uflow
/**
virtual int_type uflow();
Ensures that at least one character is available in the input area by
updating the pointers to the input area ( if needed ). On success returns
the value of that character and advances the value of the get pointer by
one character. On failure returns traits::eof().
The function may update pgtr, egptr and eback pointers to define the location
of newly loaded date ( if any ). On failure, the function ensures that either
gptr() == nullptr or gptr() == eptr.
The base class version of the function calls underflow() and increments gptr().

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
        /// no sample
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













