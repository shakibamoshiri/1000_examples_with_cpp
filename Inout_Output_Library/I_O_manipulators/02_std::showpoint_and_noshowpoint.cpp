/**
std::manipulators
c**/

/// 02_std::showpoint_and_noshowpoint
/**
Defined in header <ios>
std::ios_base& showpoint( std::ios_base& str);
std::ios_base& noshowpoint( std::ios_base& str);

Enable or disable the unconditional inclusion of the decimal point character
in floating-point output. Has no effect on input.
1)  Enable the showpoint flag in the stream str as if by calling str.setf
    ( std::ios_base::showpoint)
2)  Disable the showpoint flag in the stream str as if calling str.unsetf
    (std::ios_base::showpoint).
This is an I/O manipulator, it may be called with an expression such as
out << std::showpoint for any out of type std::basic_ostream or with an
expression such as in >> std::showbase for any in of type std::basic_istream.


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
        std::cout <<"1.0 with normal mode: "<<1.0 << std::endl
                    <<"1.0 with showpoint: "<<std::showpoint << 1.0 <<std::endl
                  <<"1.0 with noshowpoint: "<<std::noshowpoint <<1.0<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
