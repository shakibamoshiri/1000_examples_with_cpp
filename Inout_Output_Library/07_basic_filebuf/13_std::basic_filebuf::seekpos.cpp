/**
std::basic_filebuf
**/

/// protected  member :
/// 13_std::basic_filebuf::seekpos
/**

protected:
virtual  pos_type seekpos ( pos_type sp,
                           std::ios_base::openmode which = std::ios_base::in|std::ios_base::out);

Reposition the file  pointer, if possible, to the position indication by sb.
if the associated file is not open(is_open()false), fails immediately.
    if the file is open for writing, first writes the put area and any
    unshift sequences required by the currently imbued localed, using
    overflow(). Then reposition the file pointer, as if by calling std::fsetpos()
    tf the file is open for reading , updates the get are if necessary. if
    sp was not obtained by calling seekoff() or seekpos() in the same file,
    the behavior is undefined.

**/
#include <iostream>
#include <locale>
#include <fstream>
struct user_buf : std::filebuf {
    pos_type seekpos ( pos_type sp, std::ios_base::openmode which ){
        std::cout<<"before seekoff("<< sp << "), size of the get area is "
                 <<egptr()-eback() << " whit "
                 <<egptr()-gptr()<< " read position available\n";
        pos_type rc = std::filebuf::seekpos(sp, which);
        std::cout<<"seekoff() returns " << rc << "\nAfter the call,"
                 <<"size of the get area is "
                 <<egptr()-eback()<< " with "
                 <<egptr()-gptr()<<" read position available\n";
        /// uncomment if get area is emptied by seekoff()
        /// std::filebuf::underflow();
        /// std::cout<<"after forced underflow(), size of the get area is"
        ///          <<egptr()-eback()<<" with "
        ///          <<egptr()-gptr() << " read position available\n"
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
        user_buf buf;
        buf.open("test.txt", std::ios_base::in);
        std::istream stream(&buf);
        stream.get(); /// read one character to force underflow()
        stream.seekg(2);
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

