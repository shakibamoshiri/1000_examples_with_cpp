/**
std::basic_istream
**/

#include <iostream>
#include <sstream>
#include <locale>


/// 00_std::basic_istream::cin
/**
Global object cin and wcin

extern std::istream cin;
extern std::istream wcin;

    The global object std::cin and std::wcin control input from a stream buffer of implementation-defined type
( derived form std::streambuf ), associated with the standard C input stream stdin. Those object are guaranteed
to be constructed before the first constructor of a static object is called and they are guaranteed to outlive
the last destructor of a static object, so that is always possible to read from std::cin in user code
    Unless sync_with_stdio ( false ) has been issued, it is safe to concurrently access those object form
multiple threads for both formatted and unformatted input. Once std::cin is constructed, std::cin.tie() returns &std::cout,
and likewise , std::wcin.tie() returns &std::wcout. This means that and formatted input operation on std::cin
force a call to std::cout.rdbuf() if any characters are pending for output.
**/

struct Foo {
    int i;
    Foo () { /// constructor of Foo
        std::cout<<" Enter an integer number : "; /// no flush needed
        std::cin >> i;
    }
};
Foo f; /// static object
int main() {
    {
        /// mine
    }
    {
        /// the site sample
        std::cout<<" f.n is : "<< f.i << '\n';
    }
    {
        /// msdn.microsoft.com
    }

}












