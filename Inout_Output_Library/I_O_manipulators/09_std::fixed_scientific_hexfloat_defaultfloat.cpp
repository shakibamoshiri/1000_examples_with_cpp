/**
std::manipulators
c**/

/// 09_std::fixed_scientific_hexfloat_defaultfloat
/**
Defined in header <ios>
std::ios_base& fixed ( std::ios_base& str);
std::ios_base& scientific ( std::ios_base& str);
std::ios_base& hexfloat ( std::ios_base& str);
std::ios_base& defaultlfloat ( std::ios_base& str);

Modifies the default formatting for floating-point input / output.
1) Sets the floatfield of the stream str to fixed as if by calling
    str.setf( std::ios_base::fixed, std::ios_base::floatfield)
2)  Sets the floatfiled of the stream str to scientific as if by
    calling str.setf( std::ios_base::scientific, std::ios_base::floatfiled)
3)  Sets the floatfield of the stream str to fixed and scientific simultaneously
    as if by calling str.setf( std::ios_base::fixed | std::ios_base::scientific,
                              std::ios_base::floatfiled)
4)  Sets the floatfield of the stream str to zero, as if by calling
    str.unsetf( std::ios_base::floatfield). This is enable the default
    floating-point formatting, which is different from fixed and scientific

This is an I/O manipulator. It may be called with an expression
such as out <<std::hex for any out of type std::baic_ostream or
with an expression such as in >> std::hex for any in of type
 std::basic_istream
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
        std::cout<<"The number 0.01 in fixed:       "<<std::fixed <<0.01<<'\n'
                 <<"The number 0.01 in scientific   "<<std::scientific<<0.01<<'\n'
                 <<"The number 0.01 in hexfloat     "<<std::hexfloat<<0.01<<'\n'
                 <<"The number 0.01 in default      "<<std::defaultfloat<<0.01<<std::endl;
        double f;
        std::istringstream("0x1P-1022") >> std::hexfloat >> f;
        std::cout<<"Parsing 0x1P-1022 as hex gives  "<<f<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
