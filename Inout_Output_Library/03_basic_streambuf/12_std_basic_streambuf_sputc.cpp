/**
std::basic_streambuf
**/


/// 12_std::basic_streambuf::sputc
/**
int_type sputc(char_type ch);

Writes one character to the output sequence.
If the output sequence write position is not available( the buffer is full),
then calls overflow(ch).

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
        std::ostringstream s;
        s.rdbuf()->sputc('S');
        std::cout<<s.str()<<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













