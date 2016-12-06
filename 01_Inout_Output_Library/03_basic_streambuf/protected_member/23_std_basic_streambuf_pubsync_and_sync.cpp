/**
std::basic_streambuf
**/


/// 23_std::basic_streambuf::pubsync and sync
/**
int pubsync();
protected:
virtual int pubsync();

Synchronizes the controlled character sequence( the buffer) with the
associated character sequence.
1)  Calls sync() of the most derived class.
2)  The base class version of this function has no effect. The derived
    classes may override this function to allow synchronizing the
    underlaying device with the buffer.

    For output stream, this typical results in writing the contents of the
put area into the associated sequence, i.e. flushing of the output buffer.
For input streams, this typical empties the get area and forces a re-read
from the associated sequence to pick up recent changes. The default behavior
( found, for example, in std::basic_streambuf), is to do nothing.
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
        "No Sample"
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













