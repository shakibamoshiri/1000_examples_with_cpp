/**
std::basic_istream
**/


/// 05_std::basic_istream::peek
/**

int_type peek();

Behaves as UnformattedInputFunction. After construction ans testing the sentry object, read
    the next character from the input stream without extracted.

Return Value :
    if good() == true, returns next character as obtained by rdbuf()->sgetc() ;

**/
#include <iostream>
#include <sstream>


int main() {
    {
        /// mine
        std::basic_istringstream<char> s("hello world");
        char c = s.peek();
        std::cout<<"char c : " << c << std::endl;

        std::cout<<"string stream c : " << s.str() << std::endl;
        char c2 = s.get();
         c2 = s.get();
         c2 = s.get();
        std::cout<<"char c : " << c << std::endl;
        std::cout<<"string stream s : " << s.str() << std::endl;
    }
    {
        /// the site sample
        std::istringstream s1("Hello World.");
        char c1 = s1.peek();
        char c2 = s1.get();
        std::cout<<"Peeked : "<<c2 << " get : " << c2 << std::endl;
    }
    {
        /// msdn.microsoft.com
    }

}












