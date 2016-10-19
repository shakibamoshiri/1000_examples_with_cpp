/**
std::basic_stringbuf
**/

/// 02_std::basic_stringbuf::swap
/**
void swap ( std::basic_stringbuf& rhs); since c++11
Swaps the state and the contents of *this and rhs.

NOTe: This function is called automatically when swapping std::stringstream object,
it is rarely necessary to call is directly.


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

    std::cout << "Before swap, one = \"" << one.str() << '"'
              << " two = \"" << two.str() << "\"\n";

    *one.rdbuf()->swap(*two.rdbuf());

    std::cout << "Before swap, one = \"" << one.str() << '"'
              << " two = \"" << two.str() << "\"\n";
    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
