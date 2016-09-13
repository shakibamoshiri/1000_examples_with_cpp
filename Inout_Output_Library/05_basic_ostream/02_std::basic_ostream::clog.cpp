/**
std::basic_ostrream
**/


/// 02_std::basic_ostream::clog
/**
extend std::ostream clog;
extend std::ostream wclog;

    The global objects std::clog and std::wclog control output to a stream buffer
of implementation-defined type ( derived from std::streambuf ), associated with the
standard C output stream stderr, but unlikes std::cerr / std::wcerr, these stream
are not automatically flushed and not automatically tie() would with cout.

**/


#include <iostream>

struct F {
    int n;
    F(){std::clog <<"static constructor\n";}
    ~F(){std::clog <<" static destructor\n";}
};

F f;
int main()
{
    {
        /// mine
    }

    {
        /// en.reference sample
        std::clog << " main function \n";
    }

    {
        /// msdn.microsoft.com
    }

}













