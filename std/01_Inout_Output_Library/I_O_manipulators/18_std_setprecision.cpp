/**
std::manipulators
c**/

/// 18_std::setprecision
/**
Defined in header <iomanip>

|* unspecified *| setprecision ( int n );
When used in an expression out << setprecision(n) or in >> setprecision(n)
, sets the precision parameter of the stream out or in to exactly n.

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
        const long double pi = std::acos(-1.L);
        std::cout<<"Default precision (6):  "<<pi<<'\n'
                 <<"std::precision(10):     "<<std::setprecision(10)<<pi<<'\n'
                 <<"Max precision is:       "<<std::setprecision(std::numeric_limits<long double>::digits10+1)<<pi<<std::endl;
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
