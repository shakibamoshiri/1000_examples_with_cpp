/**
std::basic_istream
**/


/// 12_std::basic_istream::readsome
/**

std::streamsize readsome ( char_type* s,streamsize count );

Extracts up to count immediately available character from the input stream.
    The extracted character are stored into the character array pointed to by s.

Return value : The number of character actually extracted.


**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        char c[10] = {};
        std::cout<<"c[10] = "<<c<<std::endl;

        std::basic_istringstream<char> input("This is sample test."); /// std::stringbuf its entire
                                                                      /// buffer available for unlocking read
        input.readsome(c,5);
        std::cout<<"c[10] = "<<c<<std::endl;
        input.readsome(c,5);
        std::cout<<"c[10] = "<<c<<std::endl;
        input.readsome(c,10);
        std::cout<<"c[10] = "<<c<<std::endl;

    }

    {
        /// msdn.microsoft.com
    }

}













