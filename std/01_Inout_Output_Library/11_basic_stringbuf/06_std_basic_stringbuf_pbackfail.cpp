/**
std::basic_stringbuf
**/
/// protected member
/// 06_std::basic_stringbuf::pbackfail
/**
protected:
virtual int_type pbackfail ( int_type c = Traits::eof())
This protected virtual function is called by the public function
basic_streambuf::sungetc and basic_streambuf::sputbackc( which
is turn, are called by basic_istream::unget and basic_istream::pubback).

1)  The caller is requesting that the get area is backed up by one
    character( pbackfail() is called with no argument or with Traits::eof()
    as the argument )
    a)
    b)

2)  The caller attempts to putback a different character from the one
    retrieved earlier ( pbackfail() is called with the character that
    needs to be put  back), in which case:
    a)
    b)
    c)
    d)


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
    }

    {
        /// msdn.microsoft.com
    }

}
