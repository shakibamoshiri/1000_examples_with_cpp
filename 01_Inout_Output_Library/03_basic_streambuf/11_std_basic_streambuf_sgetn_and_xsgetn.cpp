/**
std::basic_streambuf
**/


/// 11_std::basic_streambuf::sgetn and xsgetn
/**
std::streamsize sgetn(char_type* s, std::streamsize count);
protected :
virtual std::streamsize sgetn(char_type* s, std::streamsize count);
1)  Calls xsgetn(s , count ) of the most derived class.
2)  Reads count character from the input sequence and stores them into a
    character array pointed to by s. The character are read as if by repeated
    calls to sbumpc(). That is, if less then  count characters are immediately
    available, the function calls uflow() to provide more until traits::eof()
    is returned.


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
        "no sample"
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













