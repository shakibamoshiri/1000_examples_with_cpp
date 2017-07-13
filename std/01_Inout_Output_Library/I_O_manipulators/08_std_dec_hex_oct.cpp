/**
std::manipulators
c**/

/// 08_std::dec_hex_oct
/**
Defined in header <ios>
std::ios_base& dec( std::ios_base& str);
std::ios_base& hex( std::ios_base& str);
std::ios_base& oct( std::ios_base& str);

Modifies the default numeric base for integer I/O

1)  Sets the basefiled of the stream str to dec as if by calling
    str.setf(std::ios_base::dec, std::ios_base::basefield)
2)  Sets the basefield of the stream str to hex as if by calling
    str.setf(std::ios_baee::hex, std::ios_base::basefield)
3)  Sets the basefield of the stream str to oct as if by calling
    str.setf(std::ios_base::oct, std::ios_base::basefield).
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
        std::cout<<"The number 42 in octal:    "<<std::oct<<42<<std::endl
                 <<"The number 42 in decimal:  "<<std::dec<<42<<std::endl
                 <<"The number 42 in hex:      "<<std::hex<<42<<std::endl;
        int i;
        std::istringstream("2A") >> std::hex >> i;
        std::cout<<std::dec <<"Parsing \"2A\" as hex gives "<<i<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
