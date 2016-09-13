/**
std::manipulators
c**/

/// 13_std::endl
/**

Defined in header <ostream>
template<class CharT,class Traits>
std::basic_ostream<CharT,Traits>& endl ( std::basic_ostream<CharT, Traits>& os);

Inserts a newline character into the output sequence os and flushes it as
if by calling os.put(os.widen('\n')) followed by os.flush().
This is an output-only I/O manipulator, it may be called with an
expression such as out << std::endl for any output type std::basic_ostream.

**/
#include <iostream>
#include <strstream>
#include <chrono>
template < typename diff>
void log_progress ( diff d){
    std::cout<<"...("
             <<std::chrono::duration_cast<std::chrono::milliseconds>(d).count()
             <<"ms)..."<<std::endl;
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
