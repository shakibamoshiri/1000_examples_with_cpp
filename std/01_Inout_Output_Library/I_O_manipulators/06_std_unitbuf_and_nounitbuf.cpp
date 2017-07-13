/**
std::manipulators
c**/

/// 06_std::unitbuf_and_nounitbuf
/**
Defined in header <ios>
std::ios_base& unitbuf ( std::ios_base& str);
std::ios_base& nounitbuf ( std::ios_base& str);

Enable or disable automatic flushing of the output stream after any
output operation. has no effect on input.
1)  enable the unitbuf flag in the stream str as if by calling str.
    setf(std::ios_base::unitbuf).
2)  Disable the unitbuf flag in the stream str as if by calling str.
    unsetf( std::ios_base::unitbuf).
This is an I/O manipulator, it may be called with an expression such as
out << std::unitbuf for type std::basic_ostream or with an expression
such as in >> std::unitbuf for any in of type std::basic_istream.

NOTE: Flushing is preformed in the destructor of the std::basic_ostream::sentry
object, which calls str.rdbuf()->pubsync() if str.flags() & std::ios_base::unitbuf == true.
The standard output object std::cerr and std::wcerr have their unitbuf bit set by default.


**/
#include <iostream>
#include <sstream>
#include <locale>
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
