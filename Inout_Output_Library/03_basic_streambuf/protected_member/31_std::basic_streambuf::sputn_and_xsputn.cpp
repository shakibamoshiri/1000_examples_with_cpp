/**
std::basic_streambuf
**/


/// 31_std::basic_streambuf::sputn and xsputn
/**
std::streamsize sputn ( const char_type* s, std::streamsize count );
protected:
virtual std::streamsize sputn ( const char_type* s, std::streamsize count );

1)  Calls xsputn( s, count ) of the most derived class.
2)  Writs count character to the output sequence from the character
    array whose first element is pointed to by s. The characters are
    writing as if by repeated calls to spunc(). Writing stops when
    either count character are writing or a call to sputc() would
    have returned Traits::eof(). If the put area becomes full
    ( pptr() == epptr()), this function may call overflow(), or
    achieve the effect of calling overflow() by some other, unspecified, means.

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
        std::ostringstream s1;
        std::streamsize sz = s1.rdbuf()->sputn("This is a test",14);
        s1 << std::endl;
        std::cout<< "The call to sputn() returned : "<<sz <<std::endl
                 <<"The output sequence contains : "<<s1.str();

        std::istringstream s2;
        sz = s2.rdbuf()->sputn("This is a test",14);
        std::cout<<"The call to sputn() on an input stream returned : "<<sz <<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













