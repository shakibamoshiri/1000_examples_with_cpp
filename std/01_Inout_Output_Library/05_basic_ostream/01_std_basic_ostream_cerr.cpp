/**
std::basic_ostrream
**/


/// 01_std::basic_ostream::cerr and wcerr
/**

    The global objects std::cout and std::wcout control output to the stream buffer
of implementation-defined type ( derived from std::streambuf ), associated with the
standard C output stream stdout.

**/

#include <thread>
#include <chrono>
#include <iostream>

void th(){
    std::cout<<"Output from thread ... ";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<< "... thread calls flush() " << std::endl;
}

int main()
{
    {
        /// mine
    }

    {
        /// en.reference sample
        std::thread t1(th);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::clog<<"This output form the main is not tie() would to cout\n";
        std::cerr<<"This output is tie() would to cout\n";
        t1.join();

    }

    {
        /// msdn.microsoft.com
    }

}













