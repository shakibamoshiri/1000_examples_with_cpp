/**
std::basic_filebuf
**/

/// protected  member :
/// 11_std::basic_filebuf::sefbuf
/**

protected:
virtual std::basic_streambuf<CharT, Traits>* setbuf( char_type* s, std::streamsize n);

    If s is a null pointer and n is zero, the filebuf becomes unbufferd for output,
meaning pbase() and pptr() are null and any output is immediately sent to file.
Otherwise, a call to setbuf() replaces the internal buffer ( the controlled character
sequence ) with the user-supplied character array whose first element is pointed to
by s and allows. This std::basic_filebuf object to use up to nbytes in that array
for buffering. This function is protected virtual, it may only be called through
pubsetbuf() or from member function of a user-defined class derived from std::basic::filebuf.

Note :
      The condition when this function may be used and the way in which
      provided buffer in used is implementation-defined
        GCC 4.6 libstdc++
      setbuf() may only be called when the std::basic_streambuf is not
      associated with a file ( has no effect otherwise). Whit a use-provided
      buffer, reading form file reads n-1 bytes at a time.
        Clang++3.0 libc++
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
        int c = 0;
        std::ifstream ifs;
        char buf[10000];

        ifs.rdbuf()->pubsetbuf(buf,sizeof buf);
        ifs.open("/usr/share/dict/words");

        for( std::string line; std::getline(ifs,line); )
            ++c;
        std::cout<<"Number of words is: "<<c<<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

