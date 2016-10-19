/**
std::basic_streambuf
**/


/// 06_std::basic_streambuf::pubsync and sync
/**
1)  int pubsync();
protected :
2)    virtual int sync();

Synchronizes the controlled character sequence ( the buffer ) with the
    associated character sequence.
1)  Calls sync() of the most derived class.
2)  The base class version of this function has no effect. The derived classes
    may override this function to allow synchronizing the underlying device with
    the buffer.
**/


#include <iostream>
#include <fstream>
#include <string>



int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        /// No sample
    }

    {
        /// msdn.microsoft.com
    }

}













