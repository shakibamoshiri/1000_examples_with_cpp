/**
std::basic_filebuf
**/


/// 00_std::basic_filebuf::basic_filebuf
/**
basic_filebuf();
basic_filebuf(const std::basic_filebuf& rhs) = delete;
basic_filebuf(const std::basic_filebuf&& rhs);

Constructs new std::basic_filebuf object.

1)  Constructs a std::basic_filebuf object, initializing base class by calling
    the default constructor of std::basic_streambuf. The created basic_filebuf
    is not associated with a file and is_open() return false.
2)  The copy constructor is deleted; std::basic_filebuf is not CopyConstructible
3)  Move-constructs a std::basic_filebuf object by moving all contents form another
    , the is_open variable, and all other state. After move, rhs is not associated
    with a file and rhs.is_open == false. The member pointers of the base class
    std::basic_streambuf of rhs and of the base class of *this are guaranteed to
    point to different buffer ( unless null ).
**/
#include <iostream>
#include <sstream>
#include <array>
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
    }

    {
        /// msdn.microsoft.com
    }

}

