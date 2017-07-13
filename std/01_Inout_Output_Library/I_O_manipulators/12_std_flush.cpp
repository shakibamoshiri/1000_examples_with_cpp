/**
std::manipulators
c**/

/// 12_std::flush
/**

Defined in header <ostream>
template<class CharT,class Traits>
std::basic_ostream<CharT,Traits>& flush ( std::basic_ostream<CharT, Traits>& os);

Flushes the output sequence of as if by calling of.flush().
This is an output-only I/O manipulator, it may be called with an expression
such as out << std::flush for any out of type std::basic_ostream.

Note:
This manipulator may be used to produce an incomplete line of output
immediately, e.g. when displaying output from a long-running process
, logging activity of multiple threads or logging activity of a
program that may crash unexpectedly. An explicit flush of std::cout
is also necessary before a call to std::system, if the spawned process
preforms any screen I/O ( a common example is std::system("pause") on
windows ). In most other usual interactive I/O scenarios, std::endl is
redundant when used with std::cout because any input from std::cin,
output to std::cerr, or when a complete line of output needs to be
flushed, the std::endl manipulator may be used.
When every output operation needs to be flushed, the std::unitbuf
manipulator may be used.

**/
#include <iostream>
#include <strstream>
#include <chrono>
template < typename diff>
void log_progress ( diff d){
    std::cout<<"...("
             <<std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
             <<"ms)...";
}

int main()
{
    {
        /// owner
    }
    {
        /// en.reference.com
        volatile int sink = 0;
        std::cout<< std::unitbuf; /// enable automatic flushing

        auto t1  = std::chrono::high_resolution_clock::now();
        for ( int q=0; q<5; q++){
            for (int w=0; w<10000 ; w++)
                for (int e=0; e<10000; e++)
                sink += w*e; /// do some work
            auto now = std::chrono::high_resolution_clock::now();
            log_progress(now - t1);
        }
        std::cout<<'\n';

    }

    {
        /// cplusplus.com
    }

    {
        /// msdn.microsoft.com
    }

}
