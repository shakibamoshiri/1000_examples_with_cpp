/**
std::basic_filebuf
**/

/// protected  member :
/// 06_std::basic_filebuf::shawmanyc
/**

protected :
virtual std::streamsize showmanyc();
If implementation, returns the member of characters left to read form the file.

NOTE:
This function is optional. If not implemented, the function return 0
( since the base class version std::basic_streambuf::showmanyc get called)
Whether implemented or not, this function is normally called be std::basic_streambuf::in_avail
if the get area is empty.
The name of this function stands for "stream: how many character?"
So it is  pronounced "S how many C", rather than "show many C".

**/
#include <iostream>
#include <sstream>
#include <fstream>
struct mybuf: std::filebuf{
    using std::filebuf::showmanyc;
};

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        mybuf fb;
        fb.open("TEMPFREE.cpp", std::ios_base::in);
        std::cout<<"s how many c() returns: "<<fb.showmanyc()<<std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

