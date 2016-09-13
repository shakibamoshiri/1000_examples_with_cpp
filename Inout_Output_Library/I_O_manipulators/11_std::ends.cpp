/**
std::manipulators
c**/

/// 11_std::ends
/**

Defined in header <ostream>
template <class CharT,class Traits>
std::basic_ostream<CharT,Traits>& ends ( std::basic_ostream<CharT,Traits>& os);

Inserts a null character into the output sequence os as if by calling
os.put(CharT()).
This in an output-only manipulator, it may be called with an expression
such as out << std::ends for any output type std::basic_ostream.

NOTE:
This manipulator is typically used with std::ostringstream, when the
associated output buffer needs to be null-terminated to be processed
as a C string. Unlike std::endl, this manipulator does not flush the
stream.

**/
#include <iostream>
#include <strstream>
#include <cstdio>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
       std::ostrstream oss;
       oss << "Sample text: "<<42 << std::ends;
       std::printf("%s\n",oss.str());
        oss.freeze(false); /// enable memory deallocation
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
