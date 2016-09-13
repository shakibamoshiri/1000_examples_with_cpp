/**
std::basic_stringbuf
**/
/// protected member
/// 08_std::basic_stringbuf::setbuf
/**
protected:
virtual std::basic_stringbuf<CharT, Traits>* setbuf ( char_type* s, std::streamsize n);

If s is a null pointer and n is zero, this function has no effect.
Otherwise, the effect is implementation-defined: some implementations do nothing,
while some implementations clear the std::string member currently used as the buffer
and begin using the user-supplied character array of size n, whose first element
is pointed to by s, as the buffer and the input/ output character sequence.
This function is protected virtual, it may only by called through pubsetbuf()
or form member function of a user-defined class derived form std::basic_stringbuf.

Example:
Test for the stringstrem's setbuf functionality


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
        std::ostringstream ss;
        char c[1024];
        ss.rdbuf()->pubsetbuf(c,1024);
        ss << 3.15 << std::endl;
        std::cout<<c<<std::endl;
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
