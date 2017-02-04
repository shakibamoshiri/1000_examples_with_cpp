/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>


int main(){
    // how to use sputc
    std::ostringstream oss;
    oss.rdbuf()->sputc('a');
    oss.rdbuf()->sputc('b');
    oss.rdbuf()->sputc('c');
    std::cout << oss.str() << std::endl;    // abd

    // how to use sputn
    oss.rdbuf()->sputn("ABD\n",4);
    std::cout << oss.str() << std::endl;    // abcABC

    // std::ostringstream oss2;
    // oss2.rdbuf()->xsputn("abc",3);
    // error: ‘std::streamsize std::basic_streambuf<_CharT, _Traits>::xsputn(const char_type*, std::streamsize)
    // [with _CharT = char; _Traits = std::char_traits<char>; std::streamsize = int; std::basic_streambuf<_CharT, _Traits>::char_type = char]’ is protected
}
