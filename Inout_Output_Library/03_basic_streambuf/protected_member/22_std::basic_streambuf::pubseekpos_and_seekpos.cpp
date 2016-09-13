/**
std::basic_streambuf
**/


/// 22_std::basic_streambuf::pubseekpos and seekpos
/**

pos_type pubseekpos ( pos_type pos, ios_base::openmode which = ios::base::in|ios_base::out);
protected :
virtual pos_type pubseekpos ( pos_type pos, ios_base::openmode which = ios::base::in|ios_base::out);

Sets the position indicator of the input and/or output sequence to an absolute position.
1)  Calls seekpos (pos, which) of the most derived class.
2)  The base class version of this function has no effect.
    The derived classed may override this function to allow
    absolute positioning of the position indicator.

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













