/**
std::basic_ostrream
**/


/// 00_std::basic_ostream::cout and wcout
/**

    The global objects std::cout and std::wcout control output to the stream buffer
of implementation-defined type ( derived from std::streambuf ), associated with the
standard C output stream stdout.

**/



#include <iostream>

struct F {
    int n;
    F(){std::cout << "static construction\n";}
    ~F(){std::cout<<"static destructor\n";}
};

F f;

int main()
{
    {
        /// mine
    }

    {
        /// en.reference sample
        std::cout<<"main function \n";
    }

    {
        /// msdn.microsoft.com
    }

}













