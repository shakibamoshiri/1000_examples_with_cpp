/**
std::basic_ostrream
**/


/// 07_std::basic_ostream::put
/**

basic_ostream& put ( char_type ch );

Behave as an UnformattedOutputFunction. After construction and checking
    and sentry object, writes the character ch to the output stream.
If the output fails for any reason, sets badbit.

**/


#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    {
        /// owner
    }

    {
        /// en.reference.com
    std::cout.put('a'); // normal usage
    std::cout.put('\n');

    std::ofstream s("/does/not/exist/");
    s.clear(); // pretend the stream is good
    std::cout << "Unformatted output: ";
    s.put('c'); // this will set badbit, but not failbit
    std::cout << " fail=" << bool(s.rdstate() & s.failbit);
    std::cout << " bad=" << s.bad() << '\n';
    s.clear();
    std::cout << "Formatted output:   ";
    s << 'c'; // this will set badbit and failbit
    std::cout << " fail=" << bool(s.rdstate() & s.failbit);
    std::cout << " bad=" << s.bad() << '\n';
    }

    {
        /// msdn.microsoft.com
    }

}













