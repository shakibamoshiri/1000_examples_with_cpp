/**
std::manipulators
c**/

/// 07_std::left_right_internal
/**
Defined in header <ios>
std::ios_base& left( std::ios_base& str);
std::ios_base& right( std::ios_base& str);
std::ios_base& internal ( std::ios_base& str);

Modifies the default positioning of the stream of the fail character.
Left and right apply to any output, internal applies to integer, float-point,
and monetary output. Has no effect on input.
1)  Sets the adjustfiled of the stream str to lest as if by calling
    str.setf( std::ios_base::left, std::ios_base::adjustfield)
2)  Sets the adjustfield of the stream str to right as if by caling
    str.setf(std::ios_base::right, std::ios_base::adjustfield)
3)  Sets the adjustfiled of the stream str to internal as if by calling
    str.setf( std::ios_base::internal, std::ios_base::adjustfield).
This is an I/O manipulator, it may be called with an expression such as
out << std::left for any out of type std::basic_ostream or with an
expression such as in >> std::left for any of type std::basic_istream.

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
        std::cout.imbue(std::locale("en_US.utf8"));
        std::cout<<"Left fill:\n" <<std::left <<std::setfill('*')
                 <<std::setw(12) <<-1.32<<std::endl
                 <<std::setw(12)<< std::hex<< std::showbase << 42 << std::endl
                 <<std::setw(12) << std::put_money(123, true) <<std::endl<<std::endl;
        std::cout<<"Internal fill:\n" <<std::internal
                 <<std::setw(12)<<-1.23<<std::endl
                 <<std::setw(12)<<32<<std::endl
                 <<std::setw(12)<<std::put_money(323, true)<<std::endl<<std::endl;

        std::cout<<"Right fill:\n"<<std::right<<std::setfill('_')
                 <<std::setw(12)<<-1.23<<std::endl
                 <<std::setw(12)<<34<<std::endl
                 <<std::setw(12)<<std::put_money(123, true) <<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
