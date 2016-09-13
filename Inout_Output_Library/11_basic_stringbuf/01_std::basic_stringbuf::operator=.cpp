/**
std::basic_stringbuf
**/

/// 01_std::basic_stringbuf::operator=
/**
std::basic_stringbuf& operator=( std::basic_stringbuf&& rhs); since c++11
std::basic_stringbuf& operator=( const std::basic_stringbuf& rhs) = delete;

1)  Move assignment operator: Moves the contents of rhs into *this.
    After the move, lhs has the associated string, the open mode,
    the locate, and all other state formerly head by rhs. The six
    pointer of std::basic_streambuf in lhs are guarantee to be different
    from the corresponding pointer in the moved-from rhs unless null.
2)  The copy assignment operator is deleted; basic_stringbuf is not
    CopyAssignment.
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
        std::istringstream one("one");
        std::ostringstream two("two");
        std::cout<<"Before move, one: "<<one.str() <<" | "
                 <<"two: "<<two.str() <<std::endl;

        *one.rdbuf() = std::move(*two.rdbuf());

        std::cout<<"After move, one: "<<one.str() <<" | "
                 <<"two: "<<two.str() <<std::endl; /// here has some wrong
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
