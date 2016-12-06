/**
std::basic_streambuf
**/


/// 21_std::basic_streambuf::pubseekoff and seekoff
/**
pos_type pubseekoff ( off_type off, ios_base::seekdir dir,
                    ios_base::openmode which = ios_base::in | ios_base::out );
protected:
virtual pos_type pubseekoff ( off_type off, ios_base::seekdir dir,
                    ios_base::openmode which = ios_base::in | ios_base::out );

Sets the position indicator of the input and / or output sequence relative
to some other position.
1)  calls seekoff( off, dir, which) of the most derived class.
2)  The base class version of this function has no effect. The
derived classes may override this function to allow relative
positioning of the position indicator.

Parameter: off and dir ( beg, cur, end) and which ( in , out )
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













