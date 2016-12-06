/**
std::basic_ostrream
**/


/// 04_std::basic_ostream::~basic_ostram
/**
Destroy the basic_ostream objects, This destructor does not perform any operation
    on the underlying streambuffer ( rdbuf() ) : the destructors the derived output
    streams such. as std::basic_ofstream and std::basic::ostringstream are responsible
    for calling the destructors of the stream buffers.
**/


#include <iostream>
#include <sstream>
#include <utility>

void add_words (std::basic_streambuf<char>* p){
    std::basic_ostream<char> buf(p); /// buf : share the buffer with s
    buf << " is the answer";
} /// calls the destructor of buf, p remains unaffected

int main()
{
    {
        /// mine
        std::basic_streambuf<char>* p;

        std::basic_ostringstream<char> ss("hello");
        p = ss.rdbuf();

        ss << ss.str();
        ss << " c++14";

        std::basic_ostream<char> buf2(p);
        buf2 << " and bye c++98\n";
        std::cout<<ss.str()<<std::endl;


    }

    {
        /// en.reference sample
        std::basic_ostringstream<char> ss;
        ss << 20;
        add_words(ss.rdbuf());
        ss << ".";
        std::cout<<ss.str()<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













