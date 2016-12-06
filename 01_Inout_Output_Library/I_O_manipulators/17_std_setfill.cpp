/**
std::manipulators
c**/

/// 17_std::setfill
/**
Defined in header <iomanip>
template<class CharT>
|* unspecified *| setfill ( CharT );
When used in an expression out << setfill (c) sets the fill
character of the stream out tot c;

NOTe : The current fill character may be obtained with std::ostream::fill
**/
#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
    {
        /// owner

    }
    {
        /// en.reference.com
        std::cout<<"default fill:   "<<std::setw(10)<<43<<std::endl
                 <<"setfill('*'):   "<<std::setfill('*')
                 <<std::setw(10)<<42<<std::endl;
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
