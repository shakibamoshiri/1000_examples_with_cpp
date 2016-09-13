/**
std::manipulators
c**/

/// 15_std::setiosflags
/**
Defined in header <iomanip>
|* unspecified *| setiosflat ( std::ios_base::fmtflag mask);

When used in an expression out << setiosflags (mask) or in >> setiosflags(mask)
, sets all format flags of the stream out or as specified by the mask.

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
        std::cout<< std::resetiosflags(std::ios_base::dec)
                 <<std::setiosflags(std::ios_base::hex
                                    | std::ios_base::uppercase
                                    | std::ios_base::showbase )
                 << 42 << std::endl;
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
