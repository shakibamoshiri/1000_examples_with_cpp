/**
std::basic_stringbuf
**/

/// 00_std::basic_stringbuf::basic_stringbuf
/**
1.  explicit basic_stringbuf ( std::ios_base::openmode = which = std::ios_base::in
                          | std::ios_base::out );
2.  explicit basic_stringbuf( const std::basic_string<CharT,Traits,Allocator>& new_str,
                         std::ios_base::openmode which = std::ios_base::in
                         | std::ios_base::out );
3.  basic_stringbuf( const basic_stringbuf& rhs) = delete;
4.  basic_stringbuf( basic_stringbuf&& rhs);

1)  Constructs a std::basic_stringbuf object: initialize the base class by
    calling the default constructor of std::basic_stingbuf, initialize the
    character sequence with an empty string, and sets the mode to which.
2)  Constructs a std::basic_stringbuf object by performing the same initialization
    as 1), followed by initializing the associated character sequence as if by calling
    str(new_str).
3)  The copy constructor is deleted; std::basic_stringbuf is not CopyConstructible.
4)  Move-constructs a std::basic_stringbuf object by moving all state from another
    std::basic_stringbuf object rhs, including the associated string, the open
    mode, the locale, and all other state. After the move, the six position of
    std::basic_streambuf in *this are guaranteed to be different from the
    corresponding pointer in the moved-from rhs unliss null.

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

    }

    {
        /// cplusplus.com
        /// default constructor ( mode = in|out)
        std::stringbuf buf1;
        buf1.sputc('1');
        std::cout<<&buf1<<std::endl;

        /// string constructor in at-end mode (c++11)
        std::stringbuf buf2("test", std::ios_base::in
                            | std::ios_base::out
                            | std::ios_base::app);
        buf2.sputc('1');
        std::cout<<&buf2<<std::endl;

        /// append mode test ( results differ among compilers)
        std::stringbuf buf3 ("test", std::ios_base::in
                             | std::ios_base::out
                             | std::ios_base::app);
        buf3.sputc('1');
        buf3.pubseekpos(1);
        buf3.sputc('2');
        std::cout<<&buf3<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}
