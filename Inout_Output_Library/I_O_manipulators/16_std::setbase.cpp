/**
std::manipulators
c**/

/// 16_std::setbase
/**
Defined in header <iomanip>
|* unspecified *| setbase ( int base );

Sets the numeric base of the stream . When used in an expression
out << setbase(base) or in >> setbase(base). changes the basefiled
flag of the stream out or in,depending on the value of base:
    - the value 16 sets baseflied to std::ios_base::hex
    - the value 8 sets std::ios_base::oct
    -the value 10 sets std::ios_base::dec
Values of base other them 8,10, or 16 reset bserfield to zero,
which corresponds to decimal output and prefix-dependent input.
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
        std::cout<<"Parsing string '10 010 010'\n";

        int a,b,c;
        std::istringstream s("10 0x10 010");
        s >> std::setbase(16) >> a >> b >> c;
        std::cout << "hexadecimal parse: "<<a <<' '<<b<<' '<<c<<std::endl;

        s.clear();
        s.seekg(0);
        s >> std::setbase(0) >> a >> b >> c;
        std::cout<<"Prefix-dependent parse: "<<a<<' '<<b<<' '<<c<<std::endl;

        std::cout<<"hex output: "<<std::setbase(16) << std::showbase <<a << ' '<<b <<' '<<c<<std::endl;
    }

    {
        /// cplusplus.com

    }

    {
        /// msdn.microsoft.com
    }

}
