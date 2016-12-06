/**
std::basic_filebuf
**/


/// 04_std::basic_filebuf::is_open
/**
bool is_open() const;

Returns true if the most recent call to open() succeeded and there
has been no call to close() since then.

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
        std::ifstream ifs("test_is_open.txt");
        std::filebuf fb;
        fb.open("test_is_open.txt", std::ios_base::in);
        std::cout<< std::boolalpha<<"direct call: "<<fb.is_open() << std::endl
                 <<"through streambuf: "<<ifs.rdbuf()->is_open()<< std::endl
                 <<"through fstream  : "<<ifs.is_open() << std::endl;
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}

