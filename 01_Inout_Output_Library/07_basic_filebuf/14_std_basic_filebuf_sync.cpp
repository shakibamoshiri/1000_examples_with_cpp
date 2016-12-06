/**
std::basic_filebuf
**/

/// protected  member :
/// 14_std::basic_filebuf::sync
/**

protected:
virtual int sync();
If a put area exist(e.g. the file was opened or writing ), call overflow()
to write all pending output to the file , then flushes the file as if by
calling std::flush.
If a get area exist( e,g. the file was opened for reading ), the effect is
implementation-defined. Typical implementation may empty out the get area
and move the current file position back by the corresponding number of bytes.

NOTE: sync() or its equivalent is implicitly called by close(), seefoff(),
and seekpos() and explicitly called by std::basic_streambuf::pubsync().


**/
#include <iostream>
#include <locale>
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

