/**
std::basic_filebuf
**/

/// protected  member :
/// 09_std::basic_filebuf::pbackfail
/**

protected:
virtual int_type pbackfail ( int_type c = Traits::eof() );

This protected virtual function is called by the public
function basic_streambuf::sungetc and basic_streambuf::sputbackc
( which, in turn, are called by basic_istream::unget and basic_istream::putback).
1)  The caller is requesting that the get area is backed up by one character
    ( pbackfial() is called with no arguments ), in which case this function
    re-reads the file starting one byte earlier and decerments basic_streambuf::gptr(),
    e.g. by calling gbump(-1).

2)  The caller attempts to putback a different character from the one retrieved ( syn : recover )
    earlier ( pbackfial() is called with the character that needs to be put
    back ), in which case
    a)  First, checks if there is a puback position, and if there is not, backs up
        the get area by re-reading the file starting one byte earlier.
    b)  Then checks what character is in the putback position. if the character
        held there is already equal to c, as determined by Traits::eq(to_char_type(c), pgtr()[-1],)
        then simply decrements basic_streambuf::gptr().
    c)  Otherwise, if the buffer is allowed to modify its own get area, decrements
        basic_streambuf::gptr() and writes c to the location pointed to gptr()
        after adjustment.
This function never modifies the file, only the get area of the in-memory buffer.
if the file is no open ( is_open() == false, this function returns Traits::eof() immediately

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

