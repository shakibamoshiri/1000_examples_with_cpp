/**
std::basic_streambuf
**/


/// 04_std::basic_streambuf::pubseekoff and seekoff
/**

pas_type pubseekoff( off_type off, ios_base::seekdir dir,
                    ios_base::openmode which = ios_base::in | ios_base::out );
protected :
    virtual pos_type seekoff( off_type off, ios_base::seekdir dir,
                             ios_base::openmode which = ios_base::in | ios_base::out );

Sets the position indicator of the input and / or output sequence relative to some
other position.
1)  Calls seekoff ( off, dir, which ) of the most derived class.
2)  The base class version of the function has no effect. The
    derived classes may override this function to allow relative
    positioning of the position indicator.
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
        /// No sample a
    }

    {
        /// msdn.microsoft.com
    }

}













