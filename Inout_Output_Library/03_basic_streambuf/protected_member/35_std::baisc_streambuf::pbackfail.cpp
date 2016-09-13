/**
std::basic_streambuf
**/


/// 35_std::basic_streambuf::pbackfail
/**
protected:
virtual int_type pbackfail ( int_type c = Traits::eof() );

This protected virtual function is called by the public function
sungetc() and suntbackc() ( which, in turn, are called by basic_istream::inget
                           and basic_istream::putback) when either.
1)  There is no putback position in the get area ( pbackfial () is called with
    arguments ). In thes situation, the purpose of pbackfaill () is to back
    up the get area by one character, if the associated character sequence allow
    this (e.g. a file-backed streambuf may reload the buffer from a file, starting
    one character earlier.
2)  The caller attempts to butback a different character from the one retrieved earlier
    ( pbackfail() is called with the character that need to be put back ). In this
    situation, the purpose of pbackfail() is to place the character c into the
    get area at the position just before basic_streambuf::gptr(), and if possible,
    to modify the associated character sequence to reflect this change. This may
    involve backing up the get area as in the first variant.

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
        /// no sample
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













