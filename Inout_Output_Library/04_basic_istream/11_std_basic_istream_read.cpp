/**
std::basic_istream
**/


/// 11_std::basic_istream::read
/**

basic_istream& read ( char_type* s, std::streamsize count );


**/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdio>


int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::basic_string<char> bin = {'\x13','\x13','\x13','\x13'};
        std::basic_istringstream<char> raw(bin);
        std::uint32_t n;
        raw.read(reinterpret_cast<char*> (&n), sizeof n);
        std::cout<<std::hex<<std::showbase<<n<<'\n';

        /// prepare file for next snippet
        std::basic_ofstream<char> os("test_read.txt",std::ofstream::binary );
        for ( unsigned i=0; i<10;i++){ /// prepare stream
            os << "abcd" << i << '\n';
        }
        os.close();

        /// read entire file into stream
        std::basic_ifstream<char> is("test_read.txt",std::ifstream::binary);
        if(is){
            /// get length of file
            is.seekg(0,is.end);
            int length = is.tellg();
            is.seekg(0,is.beg);

            std::basic_string<char> str;
            str.resize(length, ' '); /// reserve space
            char* begin = &*str.begin();

            is.read(begin, length);
            is.close();

            /// std::cout.operator<<(str); /// wrong because << overload on string.h not in basic_ostram
            std::cout<<str;
        }else{
            std::cout.operator<<("Could not open test_read.txt\n");
        }

    }
    {
        /// msdn.microsoft.com
    }

}













