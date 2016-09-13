/**
std::basic_streambuf
**/


/// 10_std::basic_streambuf::sgetc
/**
int_type sgetc();

Read one character form the input sequence. If the input sequence read
position in not available, returns underflow(). Otherwise returns
    Traits::to_int_type(*gptr()).
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
        std::basic_stringstream<char> stream("Hello, World");
        std::cout<<"sgetc() returned '"<<(char)stream.rdbuf()->sgetc()<<"'\n"
                 <<"peek() returned '"<<(char)stream.peek()<<"'\n"
                 <<"get() returned '"<<(char)stream.get()<<"'\n";
    }
    {
        /// cplusplus.com
        std::ifstream istr ("test_operator_stdout.txt.txt");
        if (istr) {
            std::streambuf * pbuf = istr.rdbuf();
        do {
          char ch = pbuf->sgetc();
          std::cout << ch;
        }
        while ( pbuf->snextc() != std::streambuf::traits_type::eof() );
            istr.close();
        }
    }

    {
        /// msdn.microsoft.com
    }

}













