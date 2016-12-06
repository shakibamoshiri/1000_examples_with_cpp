/**
std::basic_ostrream
**/


/// 13_std::basic_ostream::sentry
/**

class sentry;

An object of class basic_ostream::sentry is constructed in local scope at the beginning
of each member function of std::basic_ostream that performs output ( both formatted and
unformatted). Its constructor prepares the output stream: checks if the stream is already
in a failed state, flushes the tie() would output streams, and performs other implementation
-defined tasks if necessary, Implementation-defined cleanup, as well as flushing of the output
stream if necessary, is performed in the destructor, so that is guaranteed to happen if exception
are thrown during output.

Member function :
    (constructor)
    (destructor)
    operator=
    operator bool
    std::_ostream::sentry::sentry
    explicit sentry ( std::basic_ostream<charT, Traits>& os );
Prepares the stream for formatted output.

**/


#include <iostream>
#include <sstream>
#include <chrono>

struct F {
    char n[6];
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& is, F& f){
    std::basic_ostream<char>::sentry s(is);
    if(s)
        is.write(f.n, 5);
    return is;
}

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
        F f={"abcde"};
        std::cout<<f<<std::endl;
    }

    {
        /// msdn.microsoft.com
    }

}













