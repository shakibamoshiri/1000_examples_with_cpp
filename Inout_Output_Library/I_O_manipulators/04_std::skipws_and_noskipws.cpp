/**
std::manipulators
c**/

/// 04_std::skipws
/**
Defined in header <ios>
std::ios_base& skipws ( std::ios_base& str);
std::ios_base& noskipws ( std::ios_base& str);

Enable or disable  skipping of leading whitespace by the formatted input
function ( enabled by default ). Has no effect on output.
1)  Enable the skipws flag in the stream as if by calling str.strf
    (std::ios_base::skipws).
2)  Disable the skipws flag in the stream as if by calling str.unsetf
    (std::ios_base::skipwas )
The whitespace skipping is performed by the constructor of std::basic_istream::sentry,
which reads and discards the character classified as whitespace by the std::ctype facet
of the  stream's imbued locate.
This is an I/O manipulator, it may be called with an expression such as out <<
std::showpos for any out of type std::basic_ostream or with an expression such
as in >> std::noskipws for any in of type std::basic_istream.



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
        char c1, c2 ,c3;
        std::istringstream ("a b c") >> c1 >> c2 >> c3;
        std::cout<<"Default behavior: c1 and c2 and c3 : "<<c1 << ' ' <<c2<< ' '<<c3 <<std::endl;


        std::istringstream ("A B C") >> std::noskipws >> c1 >> c2 >> c3;
        std::cout<<"noskipws behavior: "<<"c1: "<<c1<<" c2: "<<c2<<" c3: "<<c3 <<std::endl;
        std::cout<<"Well here now c2 = ' ', or one whitespace\n";
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
