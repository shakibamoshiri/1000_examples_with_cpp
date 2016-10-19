/**
std::basic_streambuf
**/


/// 19_std::basic_streambuf::pubinbue and imbue // it is different with std::pubimbue public member.
/**
std::locale pubimbue ( const std::locale& loc);
protected :
virtual std::locale pubimbue ( const std::locale& loc);

Changes the associated locale.
1)  calls imbue ( loc ) of the most derived class.
2)  The base class version of the function has no effect. The derived classes
    may override this function in order to be informed about the changes of the
    locale. The derived class may cache the locale and member facets between calls
    to imbue().

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
        "No Sample"
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













