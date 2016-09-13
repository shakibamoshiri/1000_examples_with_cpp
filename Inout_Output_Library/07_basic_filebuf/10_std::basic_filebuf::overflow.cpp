/**
std::basic_filebuf
**/

/// protected  member :
/// 10_std::basic_filebuf::overflow
/**

protected:
virtual int_type overflow( int_type c = Traits::eof());

    Writes some date from the std::basic_streambuf::overflow, except
that to write the date, first uses codecvt::out() of the imbued locale
to convert the character into external ( possibly multibyte ) representation
, stored in a temporary buffer ( allocated as large as necessary ) , then uses
file I/O to copy all fully-converted bytes into the file. If th conversion fails
with std::codecvt_base::error, returns Traits::oef() without attempting any
output. If the associated file is not open ( is_open() == false ), returns Traits::oef()
before doing anything.

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
        /// no sample
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

