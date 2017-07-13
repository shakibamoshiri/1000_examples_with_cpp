/**
std::manipulators
c**/

/// 03_std::showpos_and_noshowpos
/**
Defined in header <ios>
std::ios_base& showpos ( std::ios_base& str):
std::ios_base& noshowpos ( std::ios_base& str):

Enable of disable the display of the plus sign '+' in non-negative
integer output, Has o effect on input,
1)  Enable the showpos falg in the stream str as if by calling str.setf
    ( std::ios_base::shwopos)
2)  Disable the showpos flag  in the stream str as if by calling str.unsetf
    ( std::ios_base::showpos)
This is an I/O manipulator, it may be called with an expression such out << std::showpos
for any out of type std::basic_ostream or with an expression such as in >> std::showpos
for any in of type std::basic_istream.

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
        std::cout<<"showpos: "<<std::showpos << 23 <<' '<< 3.44 <<' '<<0
                 <<"noshowpos: "<<std::noshowpos<< 23<<' ' <<3.44 <<' '<<0<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
