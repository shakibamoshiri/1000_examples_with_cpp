/**
std::manipulators
c**/

/// 01_std::showbase_noshowbase
/**
Defined in header <ios>

std::ios_base showbase ( std::ios_base& str);
std::ios_base noshowbase ( std::ios_base& str);

1)  Enable the shwobase flag in the stream str as if by calling str.serf
    (std::ios_base::showbase)
2)  Disable the showbase flag in the stream str as if by calling str.unseff
    ( std::ios_base::showbase).
This is an I/O manipulator,  it may be called with an expression such as out
<< std::showbase for any out of type std::basic_istream.
The showbase flag affect the behavior of integer output ( see::num_put::put)
, monetary input ( see std::money_get::get ) and monetary output ( see std::
money_put::put).


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
        /// showbase affects the output of octals and hexadecimals
        std::cout<<std::hex<<"showbase: "<<std::showbase << 42 << std::endl
                 <<"noshowbase: "<<std::noshowbase << 42 << std::endl;

        /// and both input and output of monetary values
        std::locale::global( std::locale("en_US.utf8"));
        long double val = 0;
        std::istringstream is("3.14");
        is >> std::showbase >> std::get_money(val);
        std::cout<<"with showbase, parsing 3.14 as money gives: "<<val <<std::endl ;
        is.seekg(0);
        is >> std::noshowbase >> std::get_money(val);
        std::cout<<"without showbase, parsing 3.14 as money gives: "<<val << std::endl;

    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
