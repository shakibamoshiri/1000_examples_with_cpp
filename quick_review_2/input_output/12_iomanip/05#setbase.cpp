/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//  setbase
//  /* unspecified */ setbase( int base )
//
//  Sets base-field flag.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators



int main(){

    std::cout << std::setbase( 16 );
    std::cout << 110 << '\n';

}
/**
6e

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.




**/
