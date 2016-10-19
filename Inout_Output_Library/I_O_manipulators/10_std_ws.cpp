/**
std::manipulators
c**/

/// 09_std::fixed_scientific_hexfloat_defaultfloat
/**
Defined in header <istream>
template<class CharT,class Traits>
std::basic_istream<CharT,Traits>& ws ( std::basic_istream<CharT,Traits>& is);

Discard leading whitespace from an input stream.

Behaves as an UnformattedInputFunction, except that is.gcount() is not
modified. After constructing and checking the sentry object, extracts
character from the stream and discards them until any one of the following
condition occurs:
    > End of file condition occurs in the input sequence ( in which case
      the function call setstate( eofbit ) but does not set failbit.
    > The next available character c in the input sequence is not whitespace
      as determined by std::issspace(c, is.getloc()). The non-whitespace
      character is not extracted.
This is an input only I/O manipulator. it may be called with an expression
such as in >> std::ws of r any in of type std::basic_istream.




**/
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        std::istringstream s("         this is a test");
        std::string line;
        std::getline( s >> std::ws, line);
        std::cout<<"ws + getline returns : \""<< line <<"\"\n";


    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
