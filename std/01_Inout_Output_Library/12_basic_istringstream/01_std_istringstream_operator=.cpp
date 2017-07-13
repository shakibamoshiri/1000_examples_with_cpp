/**
std::basic_istringstream
**/
/// 01_std::basic_istringstream::operator=
/**

basic_istringstream& operator=(basic_istringstream&& other);

Moves the string stream. The source stream becomes of invalid
state after the operation.

**/
#include <iostream>
#include <sstream>
#include <fstream>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        /// default constructor ( input / output stream )
        std::stringstream buf1;
        buf1 << 7;
        int n = 0;
        buf1 >> n;
        std::cout<<"buf1: "<<buf1.str()<<" n: "<<n<<std::endl;

        /// input stream
        std::istringstream inbuf("-10");
        inbuf >> n;
        std::cout<<"n: "<<n<<std::endl;

        /// output stream in append mode c++11
        std::ostringstream outbuf("test",std::ios_base::app);
        outbuf << '1';
        std::cout<<"outbuf: "<<outbuf.rdbuf()->str()<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
