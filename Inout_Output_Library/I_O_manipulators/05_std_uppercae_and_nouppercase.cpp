/**
std::manipulators
c**/

/// 05_std::uppercase_and_nouppercase
/**
Defined in header <ios>
std::ios_base& uppercase ( std::ios_base& str);
std::ios_base& nouppercase ( std::ios_base& str);

Enable or disable of uppercase character in floating-point and hexadecimal integer
output. Has no effect on input.
1)  Enable the uppercase flag in the stream str as if by calling str.setf
    (std::ios_base::uppercase)
2)  Disable the uppercase flag in the stream str as if by calling str.unsetf
    (std::ios_base::uppercase)
This an I/O manipulator , it may be called with an expression such as out
<< std::uppercase for any out of type std::basic_ostream or with an expression
such as in >> std::uppercase for any in type std::basic_istream.


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
        /// they work only in hex and floating-point and integer
        /// and does not work on char or string
        std::cout<<std::uppercase;
        std::istringstream is("abc");
        std::cout<<is.str()<<std::endl;

        std::cout<<std::hex<<std::showbase
                 <<"0x2a with   uppercase: "<<std::uppercase<<0x2a<<std::endl
                 <<"0x2a with  nouppercae: "<<std::nouppercase <<0x2a<<std::endl
                 <<"1e-10 with  uppercase: "<<std::uppercase<<1e-10<<std::endl
                 <<"1e-10 with nouppercae: "<<std::nouppercase <<1e-10<<std::endl;

    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
