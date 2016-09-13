/**
std::basic_streambuf
**/


/// 01_std::basic_streambuf::pubimbue and imbue
/**

std::locale pubimbue ( const std::locale& loc)
protected :
    virtual void imbue ( const std::locale& loc);

Changes the associated locale.
1) Calls imbue ( loc ) of the most derived class.
2) The base class version of the function has no effect. The derived classes may override
    this function in order to be informed about the changes of the locale. The override class
    may catch the locale and member factors between calls to imbue().


**/


#include <iostream>
#include <fstream>



int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        "no sample"
    }

    {
        /// msdn.microsoft.com
    }

}













