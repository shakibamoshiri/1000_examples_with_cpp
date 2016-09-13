/**
std::basic_iostream
**/


/// 00_std::basic_iostream::basic_iostream
/**
Construct new stream object.

1)  explicit basic_iostream ( std::basic_streambuf<charT, Traits>* sb)
2)  basic_iostream ( const basic_iostream& other);
protected:
3)  basic_iostream ( basic_iostream&& other);

1)  Initializes with streambuf sb. The base classes are initialized as
    basic_istream<charT, Traits>(sb) and basic_ostream<charT, Traits>(sb).
    After call rdbuf() == sb and gcount() == 0.
2)  Copy constructor is not allowed.
3)  Move constructor: move-constructs the first base class basic_istream
    as basic_istream<charT, Traits>(std::move(rhs));, which in turn
    move-constructs and initializes the virtual base std::basic_ios.
    The initialization of the other base, basic_ostream, is implementation-
    defined ( e.g., a protected default constructor may be added to std::
    basic_ostream: it is called by the move constructor of the derived
    stream classes std::basic_fstream and std::basic_stringstream before
    they move-constructs and associate the stream buffer.

**/
#include <iostream>
#include <sstream>
#include <array>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













