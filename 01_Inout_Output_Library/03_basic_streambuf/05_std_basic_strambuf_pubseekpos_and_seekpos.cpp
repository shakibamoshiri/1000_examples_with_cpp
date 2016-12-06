/**
std::basic_streambuf
**/


/// 05_std::basic_streambuf::pubseekpos and seekpos
/**
pos_type pubseekpos ( pos_type pos,
                    ios_base::openmode which = ios_base::in | ios_base::out );
protected :
virtual pos_type pubseekpos ( pos_type pos,
                    ios_base::openmode which = ios_base::in | ios_base::out );

Set the position indicator of the input and /or output sequence to an absolute position.
1)  Calls seekpos ( pos, which ) of the most derived class.
2)  The base class version of the function has no effect. The derived classed may override
    the function to allow absolute positioning of the position indicator.

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













