/**
std::basic_ios
**/

#include <iostream>
#include <fstream>


/// std::basic_ios::copyfmt
/**

basic_ios& copyfmt ( const basic_ios& other);

Copies the state of the stream other into *this. This is done in the following sequence :
    1. Call every callback registered by register_callback() passing erase_event as parameter
    2. Copies all member object from other to *this except for rdtater(), the exception mask, and rdbuf().
        In particular mask copies of the locale, the formatting flags, the contents of the array
        std::ios_base::iword and std::ios_base::pword ( but not the iword and pword pointers themselves ),
        the callback, and the tied system.
    3. Calls every callback registered by register_callback() passing copyfmt_event as parameter
    4. Copies the exception mask form other to *this as if by calling exceptions ( other, exception() )

**/

int main() {
    {
        /// mine : did not know
    }
    {
        /// the site sample
        std::ofstream out;

        out.copyfmt(std::cout);
        out.clear(std::cout.rdstate());
        out.basic_ios<char>::rdbuf(std::cout.rdbuf());

        out<<"Hello World";
    }

}

















