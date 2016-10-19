/**
std::basic_streambuf
**/


/// 16_std::basic_streambuf::basic_streambuf
/**
protected :
    basic_streambuf();
protected :
    basic_streambuf(const basic_streambuf& rhs); // since c++11

1)  Constructor the basic_streambuf object, initializes the six pointer members
( eback(), pgtr(), epgre(), pbase(), pptr() and epptr() ) to null pointer values,
and the locate member to std::locate(), a copy of the global c++ locate at the time
of construction.
2)  Constructs a copy of rhs, initializing the six pointers and the locate object
with the copies of the values held by rhs. Note theat this is a shallow copy: the
pointers of the newly-constructed basic_streambuf are pointing inot the same character
array as the pointers of rhs.
Both constructors are protected, and are only called by the concrete streambuf classes
, such as std::basic_filebuf , std::basic_stringbuf, or std::strstreambuf.

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
        "no sample"
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

} // end of main
