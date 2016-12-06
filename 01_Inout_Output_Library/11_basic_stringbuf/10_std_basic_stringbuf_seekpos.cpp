/**
std::basic_stringbuf
**/
/// protected member
/// 10_std::basic_stringbuf::seekpos
/**
protected:
virtual int_type seekpos( pos_type sp,
                         std::ios_base::openmode = which = std::ios_base::in|std::ios::base::out);

Reposition std::basic_streambuf::gptr() and / or std::basic_streambuf::pptr(),
if possible, to the position indicated by sb.
Effectively executes seekoff(off_type ( sp), std::ios_base::beg, which )


**/
#include <iostream>
#include <sstream>
#include <fstream>
struct mybuf: std::stringbuf {
    mybuf ( const std::string& str) : std::stringbuf(str) {} /// constructor
    pos_type seekpos( pos_type sp, std::ios_base::openmode which ){
        std::cout<<"Before seekpos (" << sp <<") , size  of the get area is: "
                 <<egptr()-eback() <<" with "
                 <<egptr()-gptr() <<" read positions available\n";
        pos_type rc =  std::stringbuf::seekpos(sp, which);
        std::cout<<"seekpos() returns: "<<rc <<".\nAfter the call, "
                 <<"size of the get area is: "
                 <<egptr()-eback()<<" with "
                 <<egptr()-gptr()<<" read position available\n";
        return rc;
    }
};
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        mybuf buf("12345");
        std::iostream stream(&buf);
        stream.seekg(2);
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
