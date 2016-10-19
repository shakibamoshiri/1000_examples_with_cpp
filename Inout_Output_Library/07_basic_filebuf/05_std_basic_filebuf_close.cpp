/**
std::basic_filebuf
**/


/// 05_std::basic_filebuf::close
/**

std::basic_filebuf<charT, Traits>* close();

If a put area exist (e.g. file was opened for writing ), first calls overflow(Traits::eod())
to write all pending output to the file, including only unshift sequence.
If the most recently called function, out of underflow(), overflow(), seekpoos(), was
overflow(), then calls std::codecvt:unshift(), perhaps multiple times, to determine the
unshift sequence according to the imbued locale, and write that sequence to the file
with overflow()(Traits::eof());
Then, close the file as if by calling std::fclose(), regardless of whether any of the
preceding calls succeeded or failed.
If any of the function calls made, including the call to std::fclose(), fails returns
a null pointer, if any of the function calls made throws an exception,the exception is
caught and re-thrown after calling std::fclose(). If the file is already closed, returns
a null pointer right away.
In any case, updates the private member variable that is associated by is_open().

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

