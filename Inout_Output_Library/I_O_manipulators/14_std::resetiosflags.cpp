/**
std::manipulators
c**/

/// 14_std::resetiosflag
/**
Defined in header <iomanip>
|* unspecified *| resetiosflags ( std::ios_base::fmtflag mask);

When used in an expression out << resetiosflag(mask) or in >> resetiosflag(mask)
clears all format flags of the stream out or in as specified by the mask.


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
    std::istringstream in ("10 010 10 010 10 010");
    int n1=0, n2=0;
    in >> std::oct >> n1 >> n2 ;
    std::cout <<"Parsing \"10 010\" with std::oct gives: "<<n1<<' '<<n2<<'\n';
    in >> std::dec >> n1 >> n2;
    std::cout <<"Parsing \"10 010\" with std::dec gives: "<<n1<<' '<<n2<<'\n';
    in >> std::resetiosflags(std::ios_base::basefield)>> n1 >> n2;
    std::cout <<"Parsing \"10 010\" with std::autodetect gives: "<<n1<<' '<<n2<<'\n';


    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
