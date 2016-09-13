/**
std::basic_istream
**/


/// 19_std::basic_istream::sentry
/**

class sentry
    An object class basic_istream::sentry is constructed in local scope at the beginning
of the each member function of std::basic_istream that performs input ( both formatte
and unformatted ). Its constructor prepares the input stream :
    checks if the stream is already in a failed state, flushes the tie() would output
    streams, skips leading whitespace unless noskipws flag is set, and performs other
    implementation-defined takes if necessary. All cleanup, if necessary, is preformed
    in the destructor, so that it is guaranteed to happen if exception are thrown during
    input.

Return value : true if the initialization of the input stream was successful, false otherwise.


**/
#include <iostream>
#include <sstream>
#include <fstream>

struct F {
    char c[5];
};

std::istream& operator>>(std::istream& is, F& f){
    std::istream::sentry b(is);
    if (b)
        is.read(f.c ,5);
        return is;
}



int main() {
    {
        /// mine
        F f;
        std::string s(" hello c++");
        std::basic_istringstream<char> st(s);

        std::istream::sentry b(st);
        st.read(f.c ,5);

        std::cout.write(f.c,5)<<std::endl;

    }
    {
        /// the site sample
        std::string input("    abcde");
        std::istringstream stream(input);
        F f;
        stream >> f;
        std::cout.write(f.c,5);
        std::cout<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













