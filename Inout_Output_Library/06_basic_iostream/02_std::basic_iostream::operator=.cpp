/**
std::basic_iostream
**/


/// 02_std::basic_iostream::operator=
/**
basic_iostream& operator=( const basic_iostream& other) = delete;
protected:
basic_iostream& operator=( basic_iostream&& other); // since c++11

Assigns another stream object.
1)  Copy assignment is not allowed.
2)  Move assign another stream object. Effectively calls swap(rhs). This move
    assignment operator is protected: it is classes std::basic_stringstream and
    std::basic_fstream which know how to properly move-assign the associated
    stream buffer.

**/
#include <iostream>
#include <sstream>
#include <array>
int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
    }
    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}













