/**
std::manipulators
c**/

/// 19_std::setw
/**
Defined in header <iomanip>
|* unspecified *| setprecision ( int n );

When used in an expression out << setw(n) or in setw(n),
sets the width parameter of the stream out orin to exactly n.

NOTE: The width property of the stream will be reset to zero( meaning "unspecified")
      if any of the any of following function are called:
      * input:
        - operator>>(basic_istream& , basic_string& )
        - operator>>(basic_ostream, char*)
      *output:
        - Overloads 1-7 of basic_ostream::operator<<()(at Stage 3 of num_put::put())
        - operator<<(basic_ostream&, char) and operator<<(basic_ostream&,char*)
        - operator<<(basic_ostream& basic_string&)
        - set::put_money( inside money_put::put())
        - std::quoted ( when used with an output stream)
The exact effect this modifier has no the input and output very between
the individual I/O functions and are described at each operator<< and operator>>
overload page individually.
**/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main()
{
    {
        /// owner

    }
    {
        /// en.reference.com
        std::cout<<"no setw:"<<42<<std::endl
                 <<"setw(6):"<<std::setw(6)<<42<<std::endl
                 <<"setw(6),several element:"<<54<<std::setw(6)<<13<<42<<std::endl;
        std::istringstream is("hello, world");
        char arr[10];
        is >> std::setw(6) >> arr;
        std::cout<<"Input from \""<<is.str()<<"\" with setw(6) gave \""
                 <<arr <<"\"\n";
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
