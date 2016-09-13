/**
std::basic_istream
**/


/// 15_std::basic_istream::seekg
/**

basic_istream& seekg( pos_type pos );
basic_istream& seekg( pos_type off, std::ios_base::seeddir dir );
    std::ios_base::seekdir:
        static constexpr seekdir beg
        static constexpr seekdir cur
        static constexpr seekdir end

    Sets input position indicator of the current associated streambuf
object. In this case of failure, calls setstate( std::ios_base::failbit ).

[Before doing anything else, seekg clear eofbit]

Return value : *this

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::string string("hello world");
        std::istringstream input(string);
        std::string w1,w2;
        input >> w1;
        input.seekg(0); /// rewind : go backwards
        input >> w2;

        std::cout<<"w 1 : "<< w1
                 <<"\nw 2 : " <<w2 << std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













