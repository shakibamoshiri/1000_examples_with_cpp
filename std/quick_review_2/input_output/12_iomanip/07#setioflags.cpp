/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
// setiosflags
//  /*unspecified*/ setiosflags (ios_base::fmtflags mask);
//  Set format flags

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators



int main(){

    std::cout << std::hex;
    std::cout << std::setiosflags( std::ios::showbase | std::ios::uppercase );
    std::cout << 100 << '\n';

}
/**
0X64

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.




**/
