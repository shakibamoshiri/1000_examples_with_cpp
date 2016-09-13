/**
std::basic_ostringstream
**/
/// 00_std::basic_ostringstream::constructor
/**
explicit basic_ostringstream( ios_base::openmode mode = ios::base::out);
explicit basic_ostringstream( const std::basic_string<CharT,Traits,Allocator>& str,
                             ios_base::openmode mode = ios_base::out );
basic_ostringstream ( basic_ostringstream&& other ) ; since c++11

Constructs new string stream.
1)  Constructs new underlying string stream. The underlying basic_stringbuf
    object is constructed as basic_stringbuf<CharT,Traits,Allocator>(mode |
    ios_base::out).
2)  Uses a copy of str as initial contents of the underlying string device.
    The underlying basic_stringbuf object is constructed as basic_stringbuf
    <CharT,Traits,Allocator>(str, mode | ios_base::out).
3)  Move constructor, Constructs the string stream with the state of other
    using move semantics

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
